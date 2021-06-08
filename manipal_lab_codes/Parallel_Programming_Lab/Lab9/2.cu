#include <stdio.h>
#include <stdlib.h>

__global__ void row_thread(int *A, int *B, int*C,int M, int N){
	int id = blockIdx.x * blockDim.x + threadIdx.x;
	if(id < M){
		for(int i=0;i<N;i++){
			C[id*N + i] = A[id*N + i] + B[id*N + i];
		}
	}
}

__global__ void col_thread(int *A, int *B, int*C,int M, int N){
	int id = blockIdx.x * blockDim.x + threadIdx.x;
	if(id < N){
		for(int i=0; i<M; i++){
			C[i*N + id] = A[i*N + id] + B[i*N + id];
		}
	}
}

__global__ void one_each_thread(int *A, int *B, int*C,int M, int N)
{
	int id = blockIdx.x * blockDim.x + threadIdx.x;
	if(id < M*N){
		C[id] = A[id] + B[id];
	}
}

int main()
{
	int *A, *B, *C, *D, *E, *d_a, *d_b, *d_c, *d_d, *d_e;
	int M, N, i, j, size;

	printf("Enter the dimensions of matrix : ");
	scanf("%d %d", &M, &N);
	
	size = M * N * sizeof(int);

	A = (int *)malloc(size);
	B = (int *)malloc(size);
	C = (int *)malloc(size);
	D = (int *)malloc(size);
	E = (int *)malloc(size);
	
	printf("Enter matrix A :\n");
	for(i=0; i<M; i++){
		for(j=0; j<N; j++){
			scanf("%d", &A[i*N + j]);
		}
	}
	
	printf("Enter matrix B :\n");
	for(i=0; i<M; i++){
		for(j=0; j<N; j++){
			scanf("%d", &B[i*N + j]);
		}
	}

	cudaMalloc((void **)&d_a, size);
	cudaMalloc((void **)&d_b, size);
	cudaMalloc((void **)&d_c, size);
	cudaMalloc((void **)&d_d, size);
	cudaMalloc((void **)&d_e, size);

	cudaMemcpy(d_a, A, size, cudaMemcpyHostToDevice);
	cudaMemcpy(d_b, B, size, cudaMemcpyHostToDevice);

	row_thread <<< 1, M >>> (d_a, d_b, d_c, M, N);
	col_thread <<< 1, N >>> (d_a, d_b, d_d, M, N);
	one_each_thread <<< 1, M*N>>> (d_a, d_b, d_e, M, N);

	cudaMemcpy(C, d_c, size, cudaMemcpyDeviceToHost);
	cudaMemcpy(D, d_d, size, cudaMemcpyDeviceToHost);
	cudaMemcpy(E, d_e, size, cudaMemcpyDeviceToHost);

	printf("Result for one thread each row :\n");
	for(i=0;i<M;i++){
		for(j=0;j<N;j++){
			printf("%d ",C[i*N + j]);
		}
		printf("\n");
	}

	printf("Result for one thread each col :\n");
	for(i=0;i<M;i++){
		for(j=0;j<N;j++){
			printf("%d ",D[i*N + j]);
		}
		printf("\n");
	}

	printf("Result for one thread each element :\n");
	for(i=0;i<M;i++){
		for(j=0;j<N;j++){
			printf("%d ",E[i*N + j]);
		}
		printf("\n");
	}
}
