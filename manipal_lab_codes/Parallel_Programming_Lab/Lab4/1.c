#include <mpi.h>
#include <stdio.h>

#define MCW MPI_COMM_WORLD

int main(int argc, char const *argv[])
{
	int rank, size, sum, fact = 1;

	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MCW, &rank);
	MPI_Comm_size(MCW, &size);

	// int fact = 1;

	for(int i=1; i <= rank+1; i++){
		fact *= i;
	}

	MPI_Scan(&fact, &sum, 1, MPI_INT, MPI_SUM, MCW);

	if(rank == size-1){
		printf("Sum of factorials is %d\n", sum);
	}
	
	MPI_Finalize();
	return 0;
}