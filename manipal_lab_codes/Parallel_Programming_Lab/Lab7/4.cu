#include <stdio.h>
#include <stdlib.h>
// #include <math.h>

__global__ void func(double *angle, double *sine){
	int idx = threadIdx.x;
	sine[idx] = sin(angle[idx]);
}

int main()
{
	double *in, *out;
	int n;
	printf("Enter the number of elements: ");
	scanf("%d",&n);

	in = (double *)malloc(n*sizeof(double));
	out = (double *)malloc(n*sizeof(double));
	
	printf("Enter the elements of the angle vector: ");
	for(int i=0; i<n; i++){
		scanf("%lf", &in[i]);
	}

	double *dIn, *dOut;
	
	int size = n*sizeof(double);

	cudaMalloc((void **)&dIn,size);
	cudaMalloc((void **)&dOut,size);

	cudaMemcpy(dIn, in, size, cudaMemcpyHostToDevice);
	cudaMemcpy(dOut, out, size, cudaMemcpyHostToDevice);

	func<<<1,n>>>(dIn, dOut);

	cudaMemcpy(out,dOut,size,cudaMemcpyDeviceToHost);

	printf("Angles and their sines are:\n");
	for(int i=0; i<n; i++){
		printf("%0.4lf\t%0.4lf\n", in[i], out[i]);
	}
	printf("\n");

	cudaFree(dIn);
	cudaFree(dOut);

	return 0;
}
