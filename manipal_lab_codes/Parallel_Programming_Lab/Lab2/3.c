#include <stdio.h>
#include <mpi.h>
#define  MCW MPI_COMM_WORLD
int main(int argc, char const *argv[])
{
	int rank, size, num;
	// char str[80];
	int a[50], buf[24];
	MPI_Init(&argc, &argv);
	MPI_Buffer_attach(buf, 96);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Status status;
	if(rank == 0){
		printf("Enter %d numbers\n", size-1);
		for(int i=0; i<size-1; i++){
			scanf("%d", &a[i]);
		}
		fflush(stdout);
		for(int i=0; i<size-1; i++){
			MPI_Bsend(&a[i], 1, MPI_INT, i+1, 1, MCW);
		}
	}
	else if(rank %2 == 0){
		MPI_Recv(&num, 1, MPI_INT, 0, 1, MPI_COMM_WORLD, &status);
		fprintf(stdout, "Process %d: %d\n", (int)rank, num*num);
		// MPI_Ssend(str, len+1, MPI_CHAR, 0, 3, MPI_COMM_WORLD/);
		// fprintf(stdout, "Received %d from process 0\n", x);
		fflush(stdout);
	}
	else{
		MPI_Recv(&num, 1, MPI_INT, 0, 1, MPI_COMM_WORLD, &status);
		fprintf(stdout, "Process %d: %d\n", (int)rank, num*num*num);
		// MPI_Ssend(str, len+1, MPI_CHAR, 0, 3, MPI_COMM_WORLD/);
		// fprintf(stdout, "Received %d from process 0\n", x);
		fflush(stdout);
	}
	MPI_Buffer_detach(&buf, 256);
	MPI_Finalize();
	return 0;
}