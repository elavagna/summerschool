#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

#define NTASKS 4

void print_buffers(int *printbuffer, int *sendbuffer, int buffersize);
void init_buffers(int *sendbuffer, int *recvbuffer, int buffersize);


int main(int argc, char *argv[])
{
    int ntasks, rank;
    int sendbuf[2 * NTASKS], recvbuf[2 * NTASKS];
    int printbuf[2 * NTASKS * NTASKS];

    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &ntasks);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    if (ntasks != NTASKS) {
        if (rank == 0) {
            fprintf(stderr, "Run this program with %i tasks.\n", NTASKS);
        }
        MPI_Abort(MPI_COMM_WORLD, -1);
    }

    /* Initialize message buffers */
    init_buffers(sendbuf, recvbuf, 2 * NTASKS);

    /* Print data that will be sent */
    print_buffers(printbuf, sendbuf, 2 * NTASKS);

    // Create a new set of communicators: one for the first two processes, one for the others
	int color, NEW_ntasks, NEW_rank;    
	if(rank < 2) {
 		color = 1;
	} else {
		color = 2;
	}
	
	MPI_Comm NEW_COMM;
	
	MPI_Comm_split(MPI_COMM_WORLD, color, rank, &NEW_COMM);
	
        MPI_Comm_size(NEW_COMM, &NEW_ntasks);
    	MPI_Comm_rank(NEW_COMM, &NEW_rank);

	MPI_Reduce(sendbuf, recvbuf, 2 * NTASKS, MPI_INT, MPI_SUM, 0, NEW_COMM); 

    /* Print data that was received */
    /* TODO: add correct buffer */
    print_buffers(printbuf, recvbuf, 2 * NTASKS);

    MPI_Finalize();
    return 0;
}


void init_buffers(int *sendbuffer, int *recvbuffer, int buffersize)
{
    int rank, i;

    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    for (i = 0; i < buffersize; i++) {
        recvbuffer[i] = -1;
        sendbuffer[i] = i + buffersize * rank;
    }
}


void print_buffers(int *printbuffer, int *sendbuffer, int buffersize)
{
    int i, j, rank, ntasks;

    MPI_Gather(sendbuffer, buffersize, MPI_INT,
               printbuffer, buffersize, MPI_INT, 0, MPI_COMM_WORLD);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &ntasks);

    if (rank == 0) {
        for (j = 0; j < ntasks; j++) {
            printf("Task %i:", j);
            for (i = 0; i < buffersize; i++) {
                printf(" %2i", printbuffer[i + buffersize * j]);
            }
            printf("\n");
        }
        printf("\n");
    }
}
