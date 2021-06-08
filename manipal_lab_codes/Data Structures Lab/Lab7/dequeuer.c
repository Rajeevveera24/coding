#include<stdio.h>
#include<string.h>
#include"deque_fun.h"
int main(){
	int op;
	char x[30];
	dequeue q;
	init(&q);
	do{
		printf("\n1.Insert(rear)\n2.Insert(front)\n3.Delete(front)\n4.Print\n5.Exit\n\nEnter your choice: ");
		scanf("%d",&op);
		switch(op){
			case 1:{
				if(full(&q)){
					printf("Queue is full\n");
				}
				else{
					printf("Enter the String: ");
					scanf("%s",x);
					enqueueR(&q,x);
				}
			}break;
			case 2:{
				if(full(&q)){
					printf("Queue is full\n");
				}
				else{
					printf("Enter the number: ");
					scanf("%s",x);
					enqueueF(&q,x);
				}
			}break;
			case 3:{
				if(empty(&q)){
					printf("Queue is empty\n");
				}
				else{
					dequeueF(&q,x);
					printf("Deleted element is %s\n",x);
				}
			}break;
			case 4:{
				print(&q);
			}break;
			default:break;
		}
	}while(op!=5);
	return 0;
}