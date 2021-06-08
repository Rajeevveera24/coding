#include <mpi.h>
#include <stdio.h>
#include <string.h>

#define MCW MPI_COMM_WORLD

int main(int argc, char const *argv[])
{
	int rank, size, len, n, sum, count, cnt[10];
	char str[80], buf[80];

	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MCW, &rank);
	MPI_Comm_size(MCW, &size);

	if(rank == 0){
		n = size;
		printf("Enter string\n");
		scanf("%s", str);
		len = strlen(str);
		len /= n;
	}

	MPI_Bcast(&len, 1, MPI_INT, 0, MCW);
	MPI_Scatter(str, len, MPI_CHAR, buf, len, MPI_CHAR, 0, MCW);

	count = 0;

	for(int i=0;  i<len; i++){
		if(buf[i] == 'a' || buf[i] == 'e' || buf[i] == 'u' || buf[i] == 'o' || buf[i] == 'i'){
			continue;
		}
		count++;
	}
	
	MPI_Gather(&count, 1, MPI_INT, cnt, 1, MPI_FLOAT, 0, MCW);

	if(rank == 0){
		fprintf(stdout, "The result has gathered in the root\n");
		fflush(stdout);
		sum = 0;
		for(int i=0; i<n; i++){
			sum += cnt[i];
			fprintf(stdout, "Process %d found %d non vowels\n", i, cnt[i]);
			fflush(stdout);
		}
		fprintf(stdout, "Total number of non vowels is %d\n", sum);
		fflush(stdout);
	}
	
	MPI_Finalize();
	return 0;
}