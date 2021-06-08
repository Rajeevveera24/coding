#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int *arr, oddSum, evenSum, size;

void *even(void *arg){
	evenSum = 0;
	for(int i=0; i<size; i++){
		if(arr[i]%2 == 0){
			evenSum += arr[i];
		}
	}
}

void *odd(void *arg){
	oddSum = 0;
	for(int i=0; i<size; i++){
		if(arr[i]%2 == 1){
			oddSum += arr[i];
		}
	}
}

int main(){
	pthread_t thread[2];
	pthread_attr_t attr;

	printf("Enter the size of the array: ");
	scanf("%d", &size);
	
	arr = (int*)malloc(size*sizeof(int));

	printf("Enter the elements of the array: ");
	for(int i=0;i<size;i++){
		scanf("%d", &arr[i]);
	}

	pthread_attr_init(&attr);

	pthread_create(&thread[0], &attr, even, NULL);
	pthread_create(&thread[1], &attr, odd, NULL);

	pthread_join(thread[0], NULL);
	pthread_join(thread[1], NULL);

	printf("The even sum is %d and the odd sum is %d\n", evenSum, oddSum);

	return 0;
}
