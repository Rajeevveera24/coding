#include <stdio.h>
#include "queue.h"

int main(){
	printf("Testing...\n");
	int *arr, size = 5, rear, front;
	initQueue(&rear, &front);
	arr = (int *)calloc(size, sizeof(int));
	enQueue(arr, size, &rear, &front, 5);
	enQueue(arr, size, &rear, &front, 7);
	printf("%d\n", arr[front]);
	printf("%d\n", arr[rear]);
	deQueue(arr, size, &rear, &front);
	printf("%d\n", arr[rear]);
	printf("%d %d\n", front, rear);
	deQueue(arr, size, &rear, &front);
	printf("%d %d\n", front, rear);
	printf("Successfully tested...\n");
	return 0;
}