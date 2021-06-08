#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int *arr, int size);
int* createArray(unsigned int size);
void printList(int *arr, int size);

int main(){
	
	int *arr = NULL, size;

	printf("Enter the size of the array:\t");
	scanf("%d",&size);

	arr = createArray(size);

	bubbleSort(arr,size);

	printList(arr,size);

	printf("\nGoodbye...\n\n");

	return 0;
}

void bubbleSort(int *a, int size){
	int opCount = 0;

	for(int i=0;i<size;i++){
		for(int j=0;j<size-i-1;j++){
			if(a[j] > a[j+1]){
				a[j] += a[j+1];
				a[j+1] = a[j] - a[j+1];
				a[j] -= a[j+1];
			}
			opCount++;
		}
	}
	printf("\nOperation count is %d\n",opCount);
}

int *createArray(unsigned int size){

	int *arr = (int*)malloc(sizeof(int) * size);

	printf("Enter the elements of the array:\t");

	for(int i=0;i<size;i++){
		scanf("%d",&arr[i]);
	}

	return arr;
}

void printList(int *arr, int size){

	printf("Elements of the list are:\t");

	for(int i = 0; i<size; i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
}
