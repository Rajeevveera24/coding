#include <mpi.h>
#include <stdio.h>

#define MCW MPI_COMM_WORLD

int main(int argc, char const *argv[])
{
	int rank, size, n = 4, mat[4][4], arr[4], row[4], count = 0, sum, num;
	// double mypi, pi, h, x, sum;

	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MCW, &rank);
	MPI_Comm_size(MCW, &size);

	if(rank == 0){
		printf("Enter the elements of the matrix of size 4x4:\n");
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				scanf("%d", &mat[i][j]);
			}
		}
	}

	// MPI_Bcast(&n, 1, MPI_INT, 0, MCW);
	// MPI_Bcast(&num, 1, MPI_INT, 0, MCW);

	MPI_Scatter(mat, n, MPI_INT, arr, n, MPI_INT, 0, MCW);

	// count = 0;

	MPI_Scan(arr, row, n, MPI_INT, MPI_SUM, MCW);

	// MPI_Reduce(&count, &sum, 1, MPI_INT, MPI_SUM, 0, MCW);

	MPI_Gather(row, n, MPI_INT, mat, n, MPI_INT, 0, MCW);

	if(rank == 0){
		printf("Resultant matrix is:\n");
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				fprintf(stdout, "%d ", mat[i][j]);
			}
			printf("\n");
		}
	}

	MPI_Finalize();

	return 0;
}

