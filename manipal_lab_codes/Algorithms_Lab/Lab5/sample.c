#include <stdio.h>
#include <stdlib.h>

void insertionSort( int *a, unsigned int size){
	int i,j,v,opCount = 0;
	for(i=1; i<size; i++){
		v = a[i];
		j = i-1;
		while(j>=0 && a[j]>v){
			a[j+1] = a[j];
			j--;
			opCount++;
		}
		a[j+1] = v;
	}
	printf("Operation count is %d\n", opCount);
}

int main(){
	int *a, size;

	printf("Enter size of array: ");
	scanf("%d", &size);

	printf("Enter the elements of the array: ");
	for(int i=0; i<size; i++){
		scanf("%d", &a[i]);
	}

	insertionSort(a, size);

	printf("Sorted array is: ");
	for(int i=0; i<size; i++){
		printf("%d ", a[i]);
	}
	printf("\n");
	return 0;
}