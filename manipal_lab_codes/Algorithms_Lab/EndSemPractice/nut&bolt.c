#include <stdio.h>

#define MAX 100

int nuts[MAX], bolts[MAX], n;

int partition(int a[], int l, int r, int p){
	int pivot = a[p]; 
	int i=l, j = r+1;
	do{
		do{
			i++;	
		}while(a[i] < pivot);
		do{
			j--;
		}while(a[j] > pivot);
		swap(&a[i] ,&arr[j]);
	}while(i<=j);
	swap(&a[i], &a[j]);
	swap(&a[j], &a[pivot]);
	return j;
}

void match(int l, int r){
	if(l<r){
		int pivot = partition(nuts, l, r, h);
		partition(bolts, l, r, pivot);
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