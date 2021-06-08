#include <stdio.h>
#include <mpi.h>
// #define MPI_COMM_WORLD M
int main(int argc, char const *argv[])
{
	int rank, size, len;
	char str[80];
	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Status status;
	if(rank == 0){
		printf("Process 0. Enter the lenght of the string: ");
		scanf("%d", &len);
		printf("Enter the string\n");
		scanf("%s", str);
		// gets(str);

		MPI_Ssend(&len, 1, MPI_INT, 1, 1, MPI_COMM_WORLD);
		MPI_Ssend(str, len+1, MPI_CHAR, 1, 2, MPI_COMM_WORLD);
		MPI_Recv(str, len+1, MPI_CHAR, 1, 3, MPI_COMM_WORLD, &status);
		fprintf(stdout, "String received from process 1 is %s\n", str);
		fflush(stdout);
	}
	else{
		MPI_Recv(&len, 1, MPI_INT, 0, 1, MPI_COMM_WORLD, &status);
		MPI_Recv(str, len+1, MPI_CHAR, 0, 2, MPI_COMM_WORLD, &status);
		fprintf("Process 1 received %s\n", str);
		for(int i=0; i<len; i++){
			(str[i] >= 97) ? (str[i] -= 32):(str[i] += 32);
		}
		MPI_Ssend(str, len+1, MPI_CHAR, 0, 3, MPI_COMM_WORLD);
		// fprintf(stdout, "Received %d from process 0\n", x);
		// fflush(stdout);
	}
	MPI_Finalize();
	return 0;
}