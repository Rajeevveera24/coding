#include <mpi.h>
#include <stdio.h>

#define MCW MPI_COMM_WORLD

int main(int argc, char const *argv[])
{
	int rank, size, len, a[40], b[10], c[40], n, cnt;

	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MCW, &rank);
	MPI_Comm_size(MCW, &size);

	if(rank == 0){
		n = size;
		fprintf(stdout, "Enter the size of array: ");
		fflush(stdout);
		scanf("%d", &len);
		printf("Enter %d elements: ", len);
		for(int i=0; i<len; i++){
			scanf("%d", &a[i]);
		}
		cnt = len / n;
	}

	MPI_Bcast(&cnt, 1, MPI_INT, 0, MCW);
	MPI_Scatter(a, cnt, MPI_INT, b, cnt, MPI_INT, 0, MCW);

	for(int i=1; i<cnt; i++){
		b[i] += b[i-1];
	}

	MPI_Gather(b, cnt, MPI_INT, c, cnt, MPI_INT, 0, MCW);

	if(rank == 0){
		fprintf(stdout, "The result has gathered in the root\n");
		fflush(stdout);
		for(int i=0; i<len; i++){
			fprintf(stdout, "%d ", c[i]);
			fflush(stdout);
		}
		printf("\n");
	}
	
	MPI_Finalize();
	return 0;
}