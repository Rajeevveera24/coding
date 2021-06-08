#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int size, totalSubsets = 0;

void printSubset(int a[], int size, int Sum){
	int sum = 0;
	for(int i=0; i<size; i++){
		sum += a[i];
	}
	if(sum != Sum){
		return;
	}
	for(int i=0; i<size; i++){
		printf("%d\t", a[i]);
	}
	printf("\n");
}

void subsetSum(int a[], int sub[], int size, int subSize, int item, int subSum, int sum){
	totalSubsets++;
	if(sum == subSum){
		printSubset(sub, subSize, sum);
		subsetSum(a, sub, size, subSize - 1, item + 1, subSum - a[item], sum);
	}
	else{
		for(int i=item; i<size; i++){
			sub[subSize] = a[i];
			subsetSum(a, sub, size, subSize+1, i+1, subSum+a[i], sum);
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
	
	subsetSum(arr, tempArray, size, 0, 0, 0, sum);
	//generateSubsets(arr, size, sum);
	free(tempArray);
	
	printf("Total number of subSets generated is %d\n", totalSubsets);
	
	return 0;
}