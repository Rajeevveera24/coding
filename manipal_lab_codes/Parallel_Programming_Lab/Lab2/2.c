#include <stdio.h>
#include <mpi.h>
#define  MCW MPI_COMM_WORLD
int main(int argc, char const *argv[])
{
	int rank, size, num;
	char str[80];
	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Status status;
	if(rank == 0){
		printf("Enter a number: ");
		scanf("%d", &num);
		fprintf(stdout, "Process 0 sending %d\n", num);
		fflush(stdout);
		for(int i=1; i<size; i++){
			MPI_Send(&num, 1, MPI_INT, i, 1, MCW);
		}
	}
	else{
		MPI_Recv(&num, 1, MPI_INT, 0, 1, MPI_COMM_WORLD, &status);
		fprintf(stdout, "Process %d received %d\n", (int)rank, num);
		// MPI_Ssend(str, len+1, MPI_CHAR, 0, 3, MPI_COMM_WORLD/);
		// fprintf(stdout, "Received %d from process 0\n", x);
		fflush(stdout);
	}
	MPI_Finalize();
	return 0;
}