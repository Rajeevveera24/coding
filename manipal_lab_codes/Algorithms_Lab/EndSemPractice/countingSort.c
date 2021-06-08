#include <stdio.h>

#define max 20

int a[max], s[max], size, c[max/2];

void countingSort(){
	for(int i=0; i<size; i++){
		c[i] = 0;
	}
	for(int i=0; i<size-1; i++){
		// c[i] = 0;
		for(int j=i+1; j<size; j++){
			if(a[i] < a[j]){
				c[j]++;
			}
			else{
				c[i]++;
			}
		}
	}
	for(int i=0; i<size; i++){
		s[c[i]] = a[i];
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
	scanf("%d", &size);
	for(int i=0; i<size; i++){
		scanf("%d", &a[i]);
	}
	countingSort();
	printArray(s, size);
	return 0;
}