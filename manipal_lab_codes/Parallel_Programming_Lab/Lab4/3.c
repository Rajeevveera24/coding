#include <mpi.h>
#include <stdio.h>

#define MCW MPI_COMM_WORLD

int main(int argc, char const *argv[])
{
	int rank, size, n, mat[3][3], arr[3], count = 0, sum, num;
	// double mypi, pi, h, x, sum;

	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MCW, &rank);
	MPI_Comm_size(MCW, &size);

	if(rank == 0){
		printf("Enter the size of the square matrix: ");
		scanf("%d", &n);
		printf("Enter the elements of the matrix:\n");
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				scanf("%d", &mat[i][j]);
			}
		}
		printf("Enter element to be searched: ");
		scanf("%d", &num);
	}

	MPI_Bcast(&n, 1, MPI_INT, 0, MCW);
	MPI_Bcast(&num, 1, MPI_INT, 0, MCW);
	MPI_Scatter(mat, n, MPI_INT, arr, n, MPI_INT, 0, MCW);

	count = 0;

	for(int i=0; i<n; i++){
		if(arr[i] == num){
			count++;
		}
	}

	MPI_Reduce(&count, &sum, 1, MPI_INT, MPI_SUM, 0, MCW);

	if(rank == 0){
		printf("The number of occurences of %d is %d\n", num, sum);
	}

	MPI_Finalize();

	return 0;
}