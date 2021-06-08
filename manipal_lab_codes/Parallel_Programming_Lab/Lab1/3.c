#include <stdio.h>
#include <mpi.h>

int main(int argc, char const *argv[])
{
	int rank;
	int a = 79, b = 12;
	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	switch(rank%4){
		case 0:{
			printf("Rank %d: %d + %d = %d\n", rank, a, b, a+b);
			break;
		}
		case 1:{
			printf("Rank %d: %d - %d = %d\n", rank, a, b, a-b);
			break;
		}
		case 2:{
			printf("Rank %d: %d * %d = %d\n", rank, a, b, a*b);
			break;
		}
		default:{
			printf("Rank %d: %d / %d = %d\n", rank, a, b, a/b);
			break;
		}
	}
	MPI_Finalize();
	return 0;
}