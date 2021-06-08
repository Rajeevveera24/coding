#include<stdio.h>
#include<stdlib.h>

void swap(int *a, int *b){
	int t = *a;
	*a  = *b;
	*b = t;
}
int partittion(int arr[], int low, int high){
	int pivot = arr[high];
	int i = low - 1;
	for(int j=low;j<high;j++){
		if(arr[j]<=pivot){
			i++;
			swap(&arr[i],&arr[j]);
		}
	}
	swap(&arr[i+1],&arr[high]);
	return (i+1);
}
void quicksort(int arr[], int low, int high){
	if(low<high){
		int pi = partittion(arr,low,high);
		quicksort(arr,low,pi-1);
		quicksort(arr,pi+1,high);
	}
}
void printArray(int *arr,int size){
	for(int i=0;i<size;i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
}
int main(){
	int *arr,size;
	printf("Enter size of the array: ");
	scanf("%d",&size);
	printf("Enter the elements of the array:\t");
	for(int i=0;i<size;i++){
		scanf("%d",&arr[i]);
	}
	quicksort(arr,0,size-1);
	printArray(arr,size);
	return 0;
}