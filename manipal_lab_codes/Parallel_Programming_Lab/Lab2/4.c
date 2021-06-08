#include <stdio.h>
#include <mpi.h>

#define MCW MPI_COMM_WORLD

int main(int argc, char const *argv[])
{
	int num, rank, size;
	MPI_Status status;
	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	if(rank == 0){
		printf("Enter the number: ");
		scanf("%d", &num);
		fprintf(stdout, "Process %d sending %d\n", rank, num);
		fflush(stdout);
		MPI_Send(&num, 1, MPI_INT, 1, 1, MCW);
		MPI_Recv(&num, 1, MPI_INT, size-1, 1, MCW, &status);
		fprintf(stdout, "Process 0 received %d\n", num);
		fflush(stdout);
	}
	else{
		MPI_Recv(&num, 1, MPI_INT, rank-1, 1, MCW, &status);
		fprintf(stdout, "Process %d received %d and sends %d\n", rank, num, num+1);
		num++;
		fflush(stdout);
		MPI_Send(&num, 1, MPI_INT, (rank+1)%size, 1, MCW);
	}
	MPI_Finalize();	
	return 0;
}