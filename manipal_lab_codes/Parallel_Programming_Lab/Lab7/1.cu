#include <stdio.h>
#include <stdlib.h>
#include <math.h>

__global__ void add_vector_block_N(int *A, int *B, int *C)
{
	int idx = blockIdx.x;
	C[idx] = A[idx] + B[idx];
}

__global__ void add_vector_thread_N(int *A, int *B, int *C)
{
	int idx = threadIdx.x;
	C[idx] = A[idx] + B[idx];
}

__global__ void add_vector_variable_N(int *A, int *B, int *C, int N)
{
	int idx = blockIdx.x * blockDim.x + threadIdx.x;
	if(idx<N){
		C[idx] = A[idx] + B[idx];
	}
}

int main()
{
	int *A,*B,*C,*D,*E;
	int N;
	printf("Enter the number of elements: ");
	scanf("%d",&N);

	A = (int *)malloc(N*sizeof(int));
	B = (int *)malloc(N*sizeof(int));
	C = (int *)malloc(N*sizeof(int));
	D = (int *)malloc(N*sizeof(int));
	E = (int *)malloc(N*sizeof(int));
	
	printf("Enter the elements of the first vector: ");
	for(int i=0;i<N;i++){
		scanf("%d", &A[i]);
	}
	printf("Enter the elements of the second vector: ");
	for(int i=0;i<N;i++){
		scanf("%d", &B[i]);
	}
	int *d_a,*d_b,*d_c,*d_d,*d_e;
	
	int size = N*sizeof(int);

	cudaMalloc((void **)&d_a,size);
	cudaMalloc((void **)&d_b,size);
	cudaMalloc((void **)&d_c,size);
	cudaMalloc((void **)&d_d,size);
	cudaMalloc((void **)&d_e,size);

	cudaMemcpy(d_a, A, size, cudaMemcpyHostToDevice);
	cudaMemcpy(d_b, B, size, cudaMemcpyHostToDevice);

	add_vector_block_N<<<N,1>>>(d_a,d_b,d_c);

	cudaMemcpy(C,d_c,size,cudaMemcpyDeviceToHost);

	printf("Block size of N: ");
	for(int i=0;i<N;i++){
		printf("%d ",C[i]);
	}
	printf("\n");

	add_vector_thread_N<<<1,N>>>(d_a,d_b,d_d);

	cudaMemcpy(D,d_d,size,cudaMemcpyDeviceToHost);

	printf("N threads: ");
	for(int i=0;i<N;i++){
		printf("%d ",C[i]);
	}
	printf("\n");

	add_vector_variable_N<<<ceil(N/256.0),256>>>(d_a, d_b, d_c, N);

	cudaMemcpy(E, d_e, size, cudaMemcpyDeviceToHost);

	printf("Variable size blocks: ");
	for(int i=0;i<N;i++){
		printf("%d ",C[i]);
	}
	printf("\n");

	cudaFree(d_a);
	cudaFree(d_b);
	cudaFree(d_c);
	cudaFree(d_d);
	cudaFree(d_e);

	return 0;
}
