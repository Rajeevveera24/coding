#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node* next;
};
typedef struct Node* Nodeptr;

void enqueue(Nodeptr head, int data){
	if(!head){
		return;
	}
	Nodeptr node = (Nodeptr)malloc(sizeof(struct Node));
	node->data = data;
	node->next = NULL;
	Nodeptr temp = head;
	while(temp->next){
		temp = temp->next;
	}
	temp->next = node;
}
void dequeue(Nodeptr head){
	if(!head || !head->next){
		return;
	}
	Nodeptr temp = head->next;
	head->next = head->next->next;
	free(temp);
}
void dispqueue(Nodeptr head){
	if(!head){
		return;
	}
	Nodeptr temp = head;
	while(temp->next){
		temp=temp->next;
		printf("%d  ",temp->data);
	}
	printf("\n");
}
int main(){
	Nodeptr head = (Nodeptr)malloc(sizeof(struct Node));
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
				printf("Enter element to be Inserted: ");
				scanf("%d",&data);
				enqueue(head,data);
			}
			break;
			case 2:{
				dequeue(head);
			}
			break;
			case 3:{
				dispqueue(head);
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