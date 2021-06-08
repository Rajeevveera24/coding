#include <stdio.h>
#include <stdlib.h>

__global__ void evaluate_power(int *A, int M, int N){
	int id = blockIdx.x * blockDim.x + threadIdx.x;
	for(int i=0;i<N;i++){
		A[id * N + i] = powf(A[id * N + i], id+1);
	}
}

int main()
{
	int *A, *d_a;
	int M, N, size;

	printf("Enter the dimensions of matrix : ");
	
	scanf("%d %d", &M, &N);
	
	A = (int *)malloc(sizeof(int) * M * N);
	
	printf("Enter matrix elements :\n");
	for(int i=0; i<M*N; i++){
		scanf("%d",&A[i]);
	}

	size = sizeof(int) * M * N;

	cudaMalloc((void **)&d_a, size);

	cudaMemcpy(d_a, A, size, cudaMemcpyHostToDevice);

	evaluate_power<<<ceil(M/256.0), M>>>(d_a, M, N);

	cudaMemcpy(A, d_a, size, cudaMemcpyDeviceToHost);

	printf("Modified Matrix:\n");
	for(int i=0;i<M;i++){
		for(int j=0;j<N;j++){
			printf("%d ",A[i*N + j]);
		}
		printf("\n");
	}

	cudaFree(d_a);

	free(A);

	return 0;
}
