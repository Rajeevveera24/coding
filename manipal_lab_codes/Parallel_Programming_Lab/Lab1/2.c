#include <stdio.h>
#include <mpi.h>

int main(int argc, char const *argv[])
{
	int rank;
	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	if(rank % 2 == 0){
		printf("%d Hello\n", rank);
	}
	else{
		printf("%d World\n", rank);
	}
	MPI_Finalize();
	// printf("\n");
	return 0;
}