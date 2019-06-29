#include <stdio.h>
#include <mpi.h>

int main(int argc, char **argv)
{
    int rank;
    int array[8][8];
    //TODO: Declare a variable storing the MPI datatype
	MPI_Datatype indexedtype;

    int i, j;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Status status;	

    // Initialize arrays
    if (rank == 0) {
        for (i = 0; i < 8; i++) {
            for (j = 0; j < 8; j++) {
                array[i][j] = (i + 1) * 10 + j + 1;
            }
        }
    } else {
        for (i = 0; i < 8; i++) {
            for (j = 0; j < 8; j++) {
                array[i][j] = 0;
            }
        }
    }

    if (rank == 0) {
        printf("Data in rank 0\n");
        for (i = 0; i < 8; i++) {
            for (j = 0; j < 8; j++) {
                printf("%3d", array[i][j]);
            }
            printf("\n");
        }
    }

    //TODO: Create datatype that describes one column. Use MPI_Type_vector.
	
	int blocklen[4] = {1, 2, 3, 4};
	int stride[4] = {0, 17, 34, 51};

	MPI_Type_indexed(4, blocklen, stride, MPI_INT, &indexedtype);
	printf("Indexed %d\n",rank);
	MPI_Type_commit(&indexedtype);
	printf("Committed %d\n",rank);
    //TODO: Send first column of matrix form rank 0 to rank 1
	if (rank == 0) { 
		MPI_Send(array, 1, indexedtype, 1, 1, MPI_COMM_WORLD);
		printf("Sent signal from rank %d\n",rank);
	}
	else {
		MPI_Recv(array, 1, indexedtype, 0, 1, MPI_COMM_WORLD, &status);
	} 

    //TODO: free datatype
	MPI_Type_free(&indexedtype);

    // Print out the result on rank 1
    // The application is correct if the first column has the values of rank 0
    if (rank == 1) {
        printf("Received data\n");
        for (i = 0; i < 8; i++) {
            for (j = 0; j < 8; j++) {
                printf("%3d", array[i][j]);
            }
            printf("\n");
        }
    }

    MPI_Finalize();

    return 0;
}
