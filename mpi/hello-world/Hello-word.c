#include <mpi.h>
#include <stdio.h>

int main(int argc, char** argv) {
	
	int rank;
	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Barrier(MPI_COMM_WORLD);
	printf("Hello world! Here rank number %d talking!\n", rank); fflush(stdout);
	MPI_Finalize();

}
 
