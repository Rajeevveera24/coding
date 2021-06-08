#include <stdio.h>
#include <mpi.h>

// short int isPrime(int x){
// 	for(int i=2; i <= x/2; i++){
// 		if(x%i == 0){
// 			return 0;
// 		}
// 	}
// 	return 1;
// }

int main(int argc, char const *argv[]){
	int rank;
	short int start, end;
	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	switch(rank){
		case 0:{
			start = 2;
			end = 50;
			break;
		}
		default:{
			start = 51;
			end = 100;
		}
	}
	// MPI_Finalize();
	for(int i=start; i<=end; i++){
		short int flag = 1;
		for(int x=2; x <= i/2; x++){
			if(i%x == 0){
				flag = 0;
				break;
			}
		}

		if(flag){
			fprintf(stdout, "%d ", i);
			fflush(stdout);
		}
	}

	MPI_Finalize();
	return 0;
}