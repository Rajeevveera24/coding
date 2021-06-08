#include <mpi.h>
#include <stdio.h>

#define MCW MPI_COMM_WORLD

int main(int argc, char const *argv[])
{
	int rank, size, len, l1, l2, l, n, cnt;
	char str1[80], str2[80], recv1[80], recv2[80], send[80], recv[80];

	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MCW, &rank);
	MPI_Comm_size(MCW, &size);

	if(rank == 0){
		n = size;
		printf("Enter the first string\n");
		scanf("%s", str1);
		len = strlen(str1);
		printf("Enter the second string\n");
		scanf("%s", str2);
		// len2 = strlen(str2);
		l1 = len / n;
		// l2 = len2 / n;
	}

	MPI_Bcast(&l1, 1, MPI_INT, 0, MCW);
	MPI_Scatter(str1, l1, MPI_CHAR, recv1, l1, MPI_CHAR, 0, MCW);
	MPI_Scatter(str2, l1, MPI_CHAR, recv2, l1, MPI_CHAR, 0, MCW);

	l = 0;
	for(int i=0; i<l1; i++){
		send[l++] = recv1[i];
		send[l++] = recv2[i];
	}

	MPI_Gather(send, l, MPI_CHAR, recv, l, MPI_CHAR, 0, MCW);

	if(rank == 0){
		fprintf(stdout, "The result has gathered in the root\n");
		fflush(stdout);
		puts(recv);
		printf("\n");
	}
	
	MPI_Finalize();
	return 0;
}