#include <mpi.h>
#include <stdio.h>

#define MCW MPI_COMM_WORLD

int fact(int x){
	int f = 1;
	for(int i=2; i<=x; i++){
		f *= i;
	}
	return f;
}
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
	c = fact(c);
	fprintf(stdout, "I have received %d in process %d\n", c, rank);
	fflush(stdout);
	MPI_Gather(&c, 1, MPI_INT, b, 1, MPI_INT, 0, MCW);
	

	if(rank == 0){
		fprintf(stdout, "The result has gathered in the root\n");
		fflush(stdout);
		c = 0;
		for(i=0; i<n; i++){
			c += b[i];
			// fflush(stdout);
		}
		fprintf(stdout, "The sum of factorials is %d\n", c);
	}
	
	MPI_Finalize();
	return 0;
}