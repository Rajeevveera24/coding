#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

int *arr;
int size, sum;

void * summation(void * arg);

int main(){
	
	pthread_t thread; 
	pthread_attr_t attr;

	printf("Enter the size of the array: ");
	scanf("%d", &size);
	arr = (int *)malloc(size * sizeof(int));

	printf("Enter array of numbers: ");
	for(int i=0;i<size; i++){
		scanf("%d", &arr[i]);
	}

	pthread_attr_init(&attr);

	pthread_create(&thread, &attr, summation, NULL);

	printf("The sum of the non negative integers is: ");
	pthread_join(thread, NULL);
	printf("%d\n",sum);

	return 0;
}

void * summation(void * arg){
	sum = 0;
	for(int i=0;i<size;i++){
		if(arr[i] > 0){
			sum += arr[i];
		}
	}
}