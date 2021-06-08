#include<mpi.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define mcw MPI_COMM_WORLD
int fact(int n)
{
	int f=1;
	for(int i=2;i<=n;i++)
	{
		f = i*f;
	}
	return f;
}
int main(int argc, char *argv[])
{
	MPI_Init(&argc,&argv);
	int rank,size,x;
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	MPI_Comm_size(MPI_COMM_WORLD,&size);
	MPI_Status status;
	if(rank == 0)
	{
		printf("Enter an integer\n");
		scanf("%d",&x);
		int s = 1;
		for(int i=1;i<size;i++)
		{
			int k = i+1;
			MPI_Send(&k,1,MPI_INT,i,1,mcw);
			MPI_Recv(&x,1,MPI_INT,i,1,mcw,&status);
			s = s + x;
		}
		
		/*for(int i=1;i<size;i++)
		{
			MPI_Recv(&x,1,MPI_INT,i,1,mcw,&status);
			s = s + x;
		}*/
		printf("Result: %d\n",s);

	}
	else
	{
		MPI_Recv(&x,1,MPI_INT,0,1,mcw,&status);
		if(x%2==0)
		{
			int sum = 0;
			for(int i=1;i<=x;i++)
				sum = sum + i;
			MPI_Send(&sum,1,MPI_INT,0,1,mcw);
		}
		else
		{
			int f = fact(x);
			MPI_Send(&f,1,MPI_INT,0,1,mcw);
		}
	}
	MPI_Finalize();
	return 0;
}