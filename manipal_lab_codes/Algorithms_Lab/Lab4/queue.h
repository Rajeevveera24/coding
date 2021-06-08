#include <stdlib.h>
//Code working fine. Use queueTest.c for testing purposes...
#define MAXSIZE 10 

void initQueue(int *r, int *f);
void deQueue(int *arr, int size, int *r , int *f);
void enQueue(int *arr, int size, int *r, int *f, int num);
//int isFullQueue();
//int isEmptyQueue(queue *q);

void initQueue(int *r, int *f){
	*r = *f = -1;
}   

void deQueue(int *arr, int size, int *r , int *f){
    if(*r == -1 || *r < *f){
        printf("Queue empty\n");
        return;
    }
    (*f)++;
    if(*f > *r){
        *f = *r = -1;
    }
}

void enQueue(int *arr, int size, int *r, int *f, int num){
	if(*r == size-1){
		printf("Queue is Full...\n");
		return;
	}
	(*r)++;
	arr[*r] = num;
	if(*f == -1){
		*f = 0;
	}
}