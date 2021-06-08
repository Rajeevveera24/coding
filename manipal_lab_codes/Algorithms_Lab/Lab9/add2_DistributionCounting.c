#include <stdio.h>

#define MAX 100

int size, S[MAX], D[MAX], A[MAX];

void print(int a[], int size){
	for(int i=0; i<size; i++){
		printf("%d ", a[i]);
	}
	printf("\n");
}

void countDistribution(int l, int u){
	for(int j = 0; j <= u-l; j++){
		D[j] = 0;
	}
	for(int i = 0; i < size; i++){
		D[A[i] - l] = D[A[i] - l] + 1;
	}
	for(int j = 1; j <= u-l; j++){
		D[j] = D[j-1] + D[j];
	}
	int j;
	print(D, u-l + 1);
	// print(S, size);
	for(int i = size-1; i >= 0; i--){
		j = A[i] - l;
		S[D[j] - 1] = A[i];
		D[j] = D[j] - 1;
	}
}

int main(){
	scanf("%d", &size);
	int min = 1000, max = 0;
	for(int i=0; i<size; i++){
		scanf("%d", &A[i]);
		if(A[i] < min){
			min = A[i];
		}
		if(A[i] > max){
			max = A[i];
		}
	}
	countDistribution(min, max);
	print(S, size);
	printf("\n");
	return 0;
}
