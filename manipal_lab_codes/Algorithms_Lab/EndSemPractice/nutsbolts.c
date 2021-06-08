#include <stdio.h>

#define MAX 100

int nuts[MAX], bolts[MAX], n;

void swap(int *x, int *y){
	int temp = *x;
	*x = *y;
	*y = temp;
}

int partition(int a[], int l, int r, int pivot){ 
	int i=l, j = r+1;

	do{
		do{
			i++;	
		}while(a[i] < pivot);
		do{
			j--;
		}while(a[j] > pivot);
		swap(&a[i] ,&a[j]);
	}while(i<=j);
	swap(&a[i], &a[j]);
	// swap(&a[j], &a[pivot]);
	return j;
}

void match(int l, int r){
	if(l<r){
		int pivot = partition(nuts, l, r, bolts[r]);
		partition(bolts, l, r, nuts[pivot]);
		match(l, pivot-1);
		match(pivot+1, r);
	}
}

void printArray(int a[], int n){
	for(int i=0; i<n; i++){
		printf("%d", a[i]);
	}
	printf("\n");
}

int main(int argc, char const *argv[])
{
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		scanf("%d", &nuts[i]);
	}
	for(int i=0; i<n; i++){
		scanf("%d", &bolts[i]);
	}
	match(0, n-1);
	printArray(nuts, n);
	printArray(bolts, n);
	return 0;
}