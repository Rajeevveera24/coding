#include <mpi.h>
#include <stdio.h>

#define MCW MPI_COMM_WORLD

int main(int argc, char const *argv[])
{
	int rank, n, a[4][4], res[4][4], arr[4], k[4], key, col[4];
	MPI_Status status;

	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MCW, &rank);
	// MPI_Comm_size(MCW, &size);
	n = 4;

	if(rank == 0){
		printf("Enter the elements of the matrix:\n");
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				scanf("%d", &a[i][j]);
			}
		}
	}

	MPI_Scatter(a, n, MPI_INT, arr, n, MPI_INT, 0, MCW);
	
	MPI_Alltoall(arr, 1, MPI_INT, col, 1, MPI_INT, MCW);

	MPI_Reduce(col, k, n, MPI_INT, MPI_BAND, 0, MCW);

	if(rank == 0){
		for(int i=0; i<3; i++){
			MPI_Send(&k[i], 1, MPI_INT, (i + 1)%n, 1, MCW);
		}
		key = k[3];
	}
	else{
		MPI_Recv(&key, 1, MPI_INT, 0, 1, MCW, &status);
	}

	for(int i=0; i<n; i++){
		arr[i] += key;
	}

	MPI_Gather(arr, n, MPI_INT, res, n, MPI_INT, 0, MCW);


	if(rank == 0){
		printf("Result is: \n\n");
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				printf("%d ", res[i][j]);
			}
			printf("\n");
		}
	}

	MPI_Finalize();

	return 0;
}