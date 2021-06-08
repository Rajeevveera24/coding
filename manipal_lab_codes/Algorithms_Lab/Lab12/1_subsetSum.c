#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int size, totalSubsets = 0;

void printSubset(int a[], int size){
	for(int i=0; i<size; i++){
		printf("%d\t", a[i]);
	}
	printf("\n");
}


void backTrack(int arr[], int subset[], int arrSize, int subSize, int subSum, int item, int sum){
	totalSubsets++;
	if(sum == subSum){
		printSubset(subset, subSize);
		backTrack(arr, subset, arrSize, subSize - 1, subSum - arr[item], item + 1, sum);
		return;
	}
	else{
		for(int i=item; i<arrSize; i++){
			subset[subSize] = arr[i];
			backTrack(arr, subset, arrSize, subSize+1, subSum + arr[i], i+1, sum);
		}
	}
}

int main(){
	int sum, arr[MAX], *tempArray;
	//size = 5;
	printf("Enter the size of the array: ");
	scanf("%d", &size);

	//arr = (int*)malloc(size*sizeof(int));
	printf("Enter the elements of the array: ");
	for(int i=0; i<size; i++){
		scanf("%d", &arr[i]);
	}

	tempArray = (int*)malloc(size * (sizeof(int)));
	
	printf("Enter the sum value: ");
	scanf("%d", &sum);
	
	backTrack(arr, tempArray, size, 0, 0, 0, sum);
	//generateSubsets(arr, size, sum);
	free(tempArray);
	
	printf("Total number of subSets generated is %d\n", totalSubsets);
	
	return 0;
}