#include<stdio.h>
#define SIZE 20
typedef struct 
{
	int data[SIZE];
	int front,rear;
}queue;
typedef struct 
{
	int data[SIZE];
	int top;
}stack;

void push(stack *s, int data){
	if(s->top == SIZE-1){
		printf("Stack is full\n");
		return;
	}
	s->top++;
	s->data[s->top] = data;
}
int pop(stack *s){
	if(s->top >= 0){
		int data = s->data[s->top];
		s->top--;
		return data;
	}
}
void enqueue(queue* q, int data){
	if(q->rear == SIZE-1){
		printf("Queue is full\n");
		return;
	}
	if(q->rear == -1){
		q->rear = q->front = 0;
	}
	else{
		q->rear++;
	}
	q->data[q->rear] = data;
}
int dequeue(queue* q){
	if(q->front>=0){
		int data = q->data[q->front];
		q->front++;
		if(q->front>q->rear){
			q->front = q->rear = -1;
		}
		return data;
	}
	printf("Queue is empty\n");
}
void dispqueue(queue* q){
	if(q->front == -1){
		printf("Queue is empty\n");
		return;
	}
	for(int i=q->front;i<=q->rear;i++){
		printf("%d  ",q->data[i]);
	}
	printf("\n");
}
int main(){
	queue q;
	stack s;
	q.front = q.rear = -1;
	s.top = -1;
	int data, option;
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
				while(data < q.data[q.rear]){
					push(&s,q.data[q.rear]);
					q.rear--;
					if(q.rear < q.front){
						q.rear = q.front = -1;
						break;
					}
				}
				enqueue(&q,data);
				while(s.top>=0){
					data = pop(&s);
					enqueue(&q,data);
				}
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
				dispqueue(&q);
			}
			break;
			default:{
				printf("Enter proper option\n");
			}
			break;
		}
	}while(1);
}