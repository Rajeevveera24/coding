#include <stdio.h>

__global__ void matMulRowByThread(int *a, int *b, int *c, int Wa, int Wb){
	
	int sum;
	int i = threadIdx.x;

	for(int j=0; j<Wb; j++){
		sum = 0;
		for(int k=0; k<Wa; k++){
			sum += a[i*Wa + k] * b[k*Wb + j];
		}
		c[i*Wb + j] = sum;
	}
}

__global__ void matMulColumnByThread(int *a, int *b, int *c, int Hb, int Ha){
	
	int sum;
	int j = threadIdx.x;

	for(int i=0; i<Ha; j++){
		sum = 0;
		for(int k=0; k<Hb; k++){
			sum += a[i*Hb + k] * b[k*blockDim.x + j];
		}
		c[i*blockDim.x + j] = sum;
	}
}

__global__ void matMulElementByThread(int *a, int *b, int *c, int Wa){
	
	int sum;
	int j = threadIdx.x;
	int i = threadIdx.y;
	for(int k=0; k<Wa; k++){
		sum += a[i*Wa + k] * b[k*blockDim.x + j];
	}
	c[i*blockDim.x + j] = sum;
}

int main()
{
	int *A, *B, *C, *D, *E;
	int ha, wa, hb, wb;
	
	printf("Enter the row and column sizes of first Matrix: ");
	scanf("%d %d", &ha, &wa);
	printf("Enter the elements of the matrix\n");
	A = (int *)malloc(ha*wa*sizeof(int));
	for(int i=0; i<ha*wa; i++){
		scanf("%d", &A[i]);
	}

	printf("Enter the row and column sizes of second Matrix: ");
	scanf("%d %d", &hb, &wb);
	printf("Enter the elements of the matrix\n");
	B = (int *)malloc(hb*wb*sizeof(int));
	for(int i=0; i<hb*wb; i++){
		scanf("%d", &B[i]);
	}

	int sizeA = ha * wa * sizeof(int);
	int sizeB = hb * wb * sizeof(int);
	int sizeC = ha * wb * sizeof(int);
	
	dim3 gridDim(1,1,1);
	dim3 blockDim(ha, 1, 1);
	
	C = (int *)malloc(sizeC);
	D = (int *)malloc(sizeC);
	E = (int *)malloc(sizeC);
	
	int *d_a,*d_b,*d_c,*d_d,*d_e;

	cudaMalloc((void **)&d_a ,sizeA);
	cudaMalloc((void **)&d_b, sizeB);
	cudaMalloc((void **)&d_c, sizeC);
	cudaMalloc((void **)&d_d, sizeC);
	cudaMalloc((void **)&d_e, sizeC);

	cudaMemcpy(d_a, A, sizeA, cudaMemcpyHostToDevice);
	cudaMemcpy(d_b, B, sizeB, cudaMemcpyHostToDevice);

	matMulRowByThread <<< gridDim, blockDim >>> (d_a, d_b, d_c, wa, wb);

	cudaMemcpy(C,d_c, sizeC, cudaMemcpyDeviceToHost);

	printf("Resultant Matrix when each row is computed by one thread:\n");
	for(int i=0; i<ha; i++){
		for(int j=0; j<wb; j++){
			printf("%d ", C[i*ha + j]);
		}
		printf("\n");
	}
	
	dim3 gridDim1(1,1,1);
	dim3 blockDim1(wb, 1, 1);

	cudaMemcpy(d_a, A, sizeA, cudaMemcpyHostToDevice);
	cudaMemcpy(d_b, B, sizeB, cudaMemcpyHostToDevice);

	matMulColumnByThread <<< gridDim1, blockDim1 >>> (d_a, d_b, d_d, hb, ha);

	cudaMemcpy(D,d_d, sizeC, cudaMemcpyDeviceToHost);

	printf("Resultant Matrix when each column is computed by one thread:\n");
	for(int i=0; i<ha; i++){
		for(int j=0; j<wb; j++){
			printf("%d ", D[i*ha + j]);
		}
		printf("\n");
	}

	dim3 gridDim2(1,1,1);
	dim3 blockDim2(wb, ha, 1);

	cudaMemcpy(d_a, A, sizeA, cudaMemcpyHostToDevice);
	cudaMemcpy(d_b, B, sizeB, cudaMemcpyHostToDevice);

	matMulElementByThread <<< gridDim2, blockDim2 >>> (d_a, d_b, d_e, wa);

	cudaMemcpy(E, d_e, sizeC, cudaMemcpyDeviceToHost);

	printf("Resultant Matrix when each element is computed by one thread:\n");
	for(int i=0; i<ha; i++){
		for(int j=0; j<wb; j++){
			printf("%d ", E[i*ha + j]);
		}
		printf("\n");
	}

	cudaFree(d_a);
	cudaFree(d_b);
	cudaFree(d_c);
	cudaFree(d_d);
	cudaFree(d_e);

	free(A);
	free(B);
	free(C);
	free(D);
	free(E);

	return 0;
}

