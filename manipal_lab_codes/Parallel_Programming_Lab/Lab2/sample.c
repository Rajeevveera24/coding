#include <stdio.h>
#include <mpi.h>

int main(int argc, char const *argv[])
{
	int rank, size, x;
	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Status status;
	if(rank == 0){
		printf("Enter a number: ");
		scanf("%d", &x);
		MPI_Send(&x, 1, MPI_INT, 1, 1, MPI_COMM_WORLD);
		fprintf(stdout, "Sent %d to Process 1\n", x);
		fflush(stdout);
	}
	else{
		MPI_Recv(&x, 1, MPI_INT, 0, 1, MPI_COMM_WORLD, &status);
		fprintf(stdout, "Received %d from process 0\n", x);
		fflush(stdout);
	}
	MPI_Finalize();
	return 0;
}