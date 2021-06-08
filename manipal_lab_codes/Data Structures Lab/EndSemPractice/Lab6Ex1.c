#include<stdio.h>
#define SIZE 5

typedef struct 
{
	int data[SIZE];
	int front,rear;
}queue;//Circular queue
void enqueue(queue* q, int data){
	if(((q->rear == SIZE - 1) && q->front == 0) || (q->rear == (q->front-1)%(SIZE - 1)) ){
		printf("queue is full\n");
		return;
	}
	else if(q->front == -1){
		q->front = q->rear = 0;
		q->data[0] = data;
	}
	else if(q->rear == SIZE -1 && q->front>0){
		q->rear = 0;
		q->data[q->rear] = data;
	}
	else{
		q->rear++;
		q->data[q->rear] = data;
	}
}
int dequeue(queue* q){
	if(q->front == -1){
		printf("queue is empty\n");
		return -1;
	}
	int temp = q->data[q->front];
	if(q->front == q->rear){
		q->front = q->rear = -1;
	}
	else if(q->front == SIZE-1){
		q->front = 0;
	}
	else{
		q->front++;
	}
	return temp;
}
void printqueue(queue *q){
	if(q->front<=q->rear){
		for(int i=q->front;i<=q->rear;i++){
			printf("%d  ",q->data[i]);
		}
	}
	else{
		for(int i=q->front;i<SIZE;i++){
			printf("%d  ",q->data[i]);
		}
		for(int i=0;i<=q->rear;i++){
			printf("%d  ",q->data[i]);
		}
	}
	printf("\n");
}
void initqueue(queue *q){
	q->front = q->rear = -1;
}
int main(){
	queue q;
	initqueue(&q);
	int option,data;
	do{
		printf("******************MENU**********************\n");
		printf("1)Insert\n2)Delete\n3)Display\n4)Exit\nChoice: ");
		scanf("%d",&option);
		if(option == 4){
			break;
		}
		switch(option){
			case 1:{
				printf("Enter the element to be Inserted: ");
				scanf("%d",&data);
				enqueue(&q,data);
			}
			break;
			case 2:{
				data = dequeue(&q);
				if(data!=-1){
					printf("Deleted element is %d\n",data);
				}
			}
			break;
			case 3:{
				printqueue(&q);
			}
			break;
			default:{
				printf("Enter proper option\n");
			}
			break;
		}
	}while(1);
	return 0;
}
