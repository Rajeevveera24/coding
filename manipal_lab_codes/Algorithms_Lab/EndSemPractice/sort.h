#include <stdio.h>
#include <stdlib.h>

int* inputArray(int size){
	int *a = (int*)malloc(size*sizeof(int));
	for(int i=0; i<size; i++){
		scanf("%d", &a[i]);
	}
	return a;
}

void printArray(int a[], int size){
	printf("\n");
	for(int i=0; i<size; i++){
		printf("%d ", a[i]);
	}
	printf("\n");
}

void swap(int *x, int* y){
	int temp = *x;
	*x = *y;
	*y = temp;
}

int selectionSort(int a[], int size){//Works...
	int count = 0;
	int j, small = 1000, pos = 0;
	for(int i=0; i<size-1; i++){
		j = i+1;
		pos = i;
		small = a[i];
		while(j<size){
			if(small>a[j]){
				small = a[j];
				pos = j;
			}
			j++;
			count++;
		}
		swap(&a[pos], &a[i]);
	}
	return count;
}

int insertionSort(int a[], int size){
	int j, small, count = 0;
	for(int i=1; i<size; i++){
		j = i-1;
		small = a[i];
		while(j>=0 && (small < a[j])){
			a[j+1] = a[j];
			j--;
			count++;
		}
		a[j+1] = small;
	}
	return count;
}

int partition(int a[], int l, int r){
	int pivot = a[l];
	int i = l;
	int j = r+1;
	do{
		do{
			i++;
		}while(a[i] < pivot);
		do{
			j--;
		}while(a[j] > pivot);
		swap(&a[i], &a[j]);
	}while(i<j);
	swap(&a[i], &a[j]);
	swap(&a[j], &a[l]);
	return j;
}

void quickSort(int a[], int l, int r){
	if(l<r){
		int p = partition(a, l, r);
		quickSort(a, l, p-1);
		quickSort(a, p+1, r);
	}
}

void merge(int a[], int l, int m, int r){
	int i,j,k = l;
	int n1 = m - l + 1;
	int n2 = r - m;
	int L[n1], R[n2];

	for(i=0; i<n1; i++){
		L[i] = a[l+i];
	}
	for(j=0; j<n2; j++){
		R[j] = a[m + 1 + j];
	}
	i = j = 0;
	while(i<n1 && j<n2){
		if(L[i] < R[j]){
			a[k++] = L[i++];
		}
		else{
			a[k++] = R[j++];
		}
	}
	while(i<n1){
		a[k++] = L[i++];
	}
	while(j<n2){
		a[k++] = R[j++];
	}
}

void mergeSort(int a[], int l, int r){
	if(l<r){
		int m = l + (r-l)/2 ;
		mergeSort(a, l, m);
		mergeSort(a, m+1, r);
		merge(a, l, m, r);
	}
}

// int main(int argc, char const *argv[]){
// 	int size;
// 	scanf("%d", &size);
// 	int *a = inputArray(size);
// 	mergeSort(a, 0, size-1);
// 	printArray(a, size);
// 	return 0;
// }