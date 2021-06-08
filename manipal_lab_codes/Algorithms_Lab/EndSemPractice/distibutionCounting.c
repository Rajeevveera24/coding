#include <stdio.h>

#define MAX 20

int a[MAX], d[MAX], s[MAX], size;

void distributionCounting(int l, int u){
	int m = u - l + 1, j;
	for(int i=0; i<m; i++){
		d[i] = 0;
	}
	for(int i=0; i<size; i++){
		d[a[i] - l]++;
	}
	for(int i=1; i<m; i++){
		d[i] += d[i-1]; 
	}
	for(int i=size-1; i>=0; i--){
		j = a[i] - l;
		s[d[j] - 1] = a[i];
		d[j]--;
	}
}

void printArray(int arr[], int size){
	for(int i=0; i<size; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int main(int argc, char const *argv[])
{
	int max = -1000, min = 1000;
	scanf("%d", &size);
	for(int i=0; i<size; i++){
		scanf("%d", &a[i]);
		if(a[i] > max){
			max = a[i];
		}
		if(a[i] < min){
			min = a[i];
		}
	}
	distributionCounting(min, max);
	printArray(s, size);
	return 0;
}