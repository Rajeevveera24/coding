#include<stdio.h>
#include<stdlib.h>

struct Node	 
{		
	int data;
	struct Node* next;
};
typedef struct Node* Nodeptr;

void add(Nodeptr *head_ref, int data){

	Nodeptr last  = (Nodeptr)malloc(sizeof(struct Node));
	last->data = data;
	last->next = *head_ref;

	if(*head_ref != NULL){
		Nodeptr temp = *head_ref;
		while(temp->next != *head_ref){
			temp = temp->next;
		}
		temp->next = last;
	}
	else{
		last->next = last;
	}
	*head_ref = last;
}
void delete(Nodeptr head){
	if(!head){
		return;
	}
	Nodeptr cur = head,prev;
	while(cur->next != head){
		prev = cur;
		cur = cur->next;
	}
	prev->next = cur->next;
	free(cur);
}
void display(Nodeptr node){
	if(!node){
		printf("Empty List\n");
		return;
	}
	Nodeptr temp = node;
	do{
		printf("%d  ",temp->data);
		temp = temp->next;
	}while(temp != node);
	printf("\n");
}
int ispresent(Nodeptr node, int data){
	if(!node){
		return 0;
	}
	Nodeptr temp = node;
	while(temp->next != node){
		if(temp->data == data){
			return 1;
		}
		temp = temp->next;
	}
	if(temp->data == data){
		return 1;
	}
	return 0;
}

Nodeptr getunion(Nodeptr node1, Nodeptr node2){
	Nodeptr Union = NULL;
	Nodeptr temp = node1;

	do{
		if(!ispresent(Union,temp->data)){
			add(&Union,temp->data);
		}
		temp = temp->next;
	}while(temp != node1);

	temp = node2;

	do{
		if(!ispresent(Union,temp->data)){
			add(&Union,temp->data);
		}
		temp = temp->next;
	}while(temp != node2);

	return Union;
}

Nodeptr getintersection(Nodeptr node1, Nodeptr node2){
	Nodeptr intersection = NULL;
	Nodeptr temp = node1;

	do{
		if(ispresent(node2,temp->data)){
			add(&intersection,temp->data);
		}
		temp = temp->next;
	}while(temp != node1);
	return intersection;
}

int main(){
	Nodeptr node1 = NULL;
	Nodeptr node2 = NULL;
	Nodeptr intersection;
	Nodeptr Union;

	add(&node1,5);
	add(&node1,6);
	add(&node1,7);
	add(&node1,8);
	add(&node1,9);

	add(&node2,5);
	add(&node2,6);
	add(&node2,7);
	add(&node2,10);
	add(&node2,11);

	intersection = getintersection(node1,node2);
	Union = getunion(node1,node2);

	display(intersection);
	display(Union);

	return 0;
}