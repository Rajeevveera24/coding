#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void swap(int *x, int *y){
	int temp = *x;
	*x= *y;
	*y = temp;
}

void generatePermutations(int a[], int l, int r){
	if(l==r){
		for(int i=0; i<=r; i++){
			printf("%d", a[i]);
		}
		printf("\n");
	}
	else{
		for(int i=l; i<=r; i++){
			swap(a+l, a+i);
			generatePermutations(a, l+1, r);
			swap(a+l, a+i);
		}
	}
}

void generateSubsets(int a[], int size){
	int numSet = pow(2, size);
	// int b[size];
	for(int i=0; i<numSet; i++){
		int j = 0;
		while(j<size){
			if(i & (1<<j)){
				printf("%d ", a[j]);
			}
			j++;
		}
		printf("\n");
	}
}

int main(int argc, char const *argv[])
{
	int size;
	scanf("%d", &size);
	int *a = (int*)malloc(size*sizeof(int));
	for(int i=0; i<size; i++){
		a[i] = i+1;
	}
	generatePermutations(a, 0, size-1);
	generateSubsets(a, size);
	return 0;
}