#include <stdio.h>
#include <stdlib.h>
#include <math.h>

__global__ void func(int *y, int *x, int *a)
{
	int idx = threadIdx.x;
	y[idx] = *a * x[idx] + y[idx];
}

int main()
{
	int *x, *y, a;
	int n;
	printf("Enter the number of elements: ");
	scanf("%d",&n);

	x = (int *)malloc(n*sizeof(int));
	y = (int *)malloc(n*sizeof(int));
	// C = (int *)malloc(N*sizeof(int));
	// D = (int *)malloc(N*sizeof(int));
	// E = (int *)malloc(N*sizeof(int));
	
	printf("Enter the elements of the vector X: ");
	for(int i=0; i<n; i++){
		scanf("%d", &x[i]);
	}
	
	printf("Enter the elements of the vector Y: ");
	for(int i=0; i<n; i++){
		scanf("%d", &y[i]);
	}

	printf("Enter the value of a: ");
	scanf("%d", &a);

	int *dX, *dY, *dA;
	
	int size = n*sizeof(int);

	cudaMalloc((void **)&dX,size);
	cudaMalloc((void **)&dY,size);
	cudaMalloc((void **)&dA,1);

	cudaMemcpy(dY, y, size, cudaMemcpyHostToDevice);
	cudaMemcpy(dX, x, size, cudaMemcpyHostToDevice);
	cudaMemcpy(dA, &a, 1, cudaMemcpyHostToDevice);

	func<<<1,n>>>(dY, dX, dA);

	cudaMemcpy(y,dY,size,cudaMemcpyDeviceToHost);

	printf("Vector Y has the values: ");
	for(int i=0; i<n; i++){
		printf("%d ",y[i]);
	}
	printf("\n");

	cudaFree(dX);
	cudaFree(dY);
	cudaFree(dA);

	return 0;
}
