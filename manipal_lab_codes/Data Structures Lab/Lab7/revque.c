#include<stdio.h>
#include"revque.h"
int main(){
	queue q;
	stack s;
	init(&q);
	inits(&s);
	int num;
	printf("Enter the queue of 10 integers\n");
	for(int i=0;i<10;i++){
		scanf("%d",&num);
		enqueue(&q,num);
	}
	while(!empty(&q)){
		num = dequeue(&q);
		push(&s,num);
	}
	init(&q);
	while(!emptys(&s)){
		num = pop(&s);
		enqueue(&q,num);
	}
	print(&q);
	return 0;
}