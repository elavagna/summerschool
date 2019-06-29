#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

int main(int argc, char *argv[])
{
    int i, myid, ntasks;
    int msgsize = 10000000;
    int *message;
    int *receiveBuffer;
    MPI_Status status;
	MPI_Request requests[2];
	MPI_Status statuses[2];

    double t0, t1;

    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &ntasks);
    MPI_Comm_rank(MPI_COMM_WORLD, &myid);

    /* Allocate message buffers */
    message = (int *)malloc(sizeof(int) * msgsize);
    receiveBuffer = (int *)malloc(sizeof(int) * msgsize);
    /* Initialize message */
    for (i = 0; i < msgsize; i++) {
        message[i] = myid;
    }

    /* Start measuring the time spent in communication */
    MPI_Barrier(MPI_COMM_WORLD);
    t0 = MPI_Wtime();

	// Describing the requests, both receiving and sending
	if (myid < ntasks -1)	MPI_Send_init(message, msgsize, MPI_INT, myid + 1, myid + 1, MPI_COMM_WORLD, &requests[0]);
	if (myid > 0)	MPI_Recv_init(receiveBuffer, msgsize, MPI_INT, myid - 1, myid, MPI_COMM_WORLD, &requests[1]);
	
    /* Send messages */
    if (myid < ntasks - 1) {
        MPI_Start(&requests[0]);
        printf("Sender: %d. Sent elements: %d. Tag: %d. Receiver: %d\n",
               myid, msgsize, myid + 1, myid + 1);
    }
    /* Receive messages */
    if (myid > 0) {
        MPI_Start(&requests[1]);
        printf("Receiver: %d. first element %d.\n",
               myid, receiveBuffer[0]);
    }
	// Doing the block
	MPI_Wait(&requests[0], &statuses[0]);	
	MPI_Wait(&requests[1], &statuses[1]);	
	//Clea up the requests
	MPI_Request_free(&requests[0]);
	MPI_Request_free(&requests[1]);

    /* Finalize measuring the time and print it out */
    t1 = MPI_Wtime();
    MPI_Barrier(MPI_COMM_WORLD);
    fflush(stdout);

    printf("Time elapsed in rank %2d: %7.6f\n", myid, t1 - t0);

    free(message);
    free(receiveBuffer);
    MPI_Finalize();
    return 0;
}
