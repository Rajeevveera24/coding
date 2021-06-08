#include <mpi.h>
#include <stdio.h>

#define MCW MPI_COMM_WORLD

int main(int argc, char const *argv[])
{
	int rank, size, n;
	double mypi, pi, h, x, sum;

	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MCW, &rank);
	MPI_Comm_size(MCW, &size);

	while(1){
		
		if(rank == 0){
			scanf("%d", &n);
		}

		MPI_Bcast(&n, 1, MPI_INT, 0, MCW);

		if(n == 0){
			break;
		}
		else{
			h = 1.0/(double)n;
			sum = 0.0;

			for(int i= rank + 1; i<=n; i += size){
				x = h*((double)i + 0.5);
				sum += 4.0/(1.0 + x*x); 
			}

			mypi = h*sum;

			MPI_Reduce(&mypi, &pi, 1, MPI_DOUBLE, MPI_SUM, 0, MCW);

			if(rank == 0){
				printf("pi is approximately %0.10lf\n", pi);
			}
		}
	}
	
	MPI_Finalize();
	return 0;
}