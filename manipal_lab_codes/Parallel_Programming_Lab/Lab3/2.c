#include <mpi.h>
#include <stdio.h>

#define MCW MPI_COMM_WORLD

int main(int argc, char const *argv[])
{
	int rank, size, m, n, a[100], sum = 0;
	int b[10];
	float avg, c[10], sum1;


	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MCW, &rank);
	MPI_Comm_size(MCW, &size);

	if(rank == 0){
		n = size;
		fprintf(stdout, "Enter value of m: ");
		fflush(stdout);
		scanf("%d", &m);
		printf("Enter %d elements: ", m*n);
		for(int i=0; i<m*n; i++){
			scanf("%d", &a[i]);
		}
	}

	MPI_Bcast(&m, 1, MPI_INT, 0, MCW);
	MPI_Scatter(a, m, MPI_INT, b, m, MPI_INT, 0, MCW);
	
	// fprintf(stdout, "I have received %0.2f in process %d\n", b[0], rank);
	fflush(stdout);

	for(int i=0; i<m; i++){
		sum += b[i];
	}
	avg = (float)((float)sum/(float)m);

		fprintf(stdout, "average of process %d is %0.2f\n", rank, avg);
		fflush(stdout);

	MPI_Gather(&avg, 1, MPI_FLOAT, c, 1, MPI_FLOAT, 0, MCW);

	if(rank == 0){
		fprintf(stdout, "The result has gathered in the root\n");
		fflush(stdout);
		sum1 = 0;
		for(int i=0; i<n; i++){
			sum1 += c[i];
			// fprintf(stdout, "%0.2f\n", c[i]);
			// fflush(stdout);
		}
		avg = (float)((float)sum1/(float)n);
		fprintf(stdout, "Total average is %0.2f\n", avg);
		fflush(stdout);
	}
	
	MPI_Finalize();
	return 0;
}