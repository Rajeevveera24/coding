#include <mpi.h>
#include <stdio.h>

#define MCW MPI_COMM_WORLD

int main(int argc, char const *argv[])
{
	int rank, size, n, a[10], b[10], c, i;

	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MCW, &rank);
	MPI_Comm_size(MCW, &size);

	if(rank == 0){
		n = size;
		fprintf(stdout, "Enter %d values:\n", n);
		fflush(stdout);
		for(int i=0; i<n; i++){
			scanf("%d", &a[i]);
		}
	}
	MPI_Scatter(a, 1, MPI_INT, &c, 1, MPI_INT, 0, MCW);
	fflush(stdout);
	c = c*c;

	MPI_Gather(&c, 1, MPI_INT, b, 1, MPI_INT, 0, MCW);
	fprintf(stdout, "I have received %d in process %d\n", c, rank);

	if(rank == 0){
		fprintf(stdout, "The result has gathered in the root\n");
		fflush(stdout);
		for(i=0; i<n; i++){
			fprintf(stdout, "%d ", b[i]);
			fflush(stdout);
		}
	}
	
	MPI_Finalize();
	return 0;
}