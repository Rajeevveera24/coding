#include <stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node *next,*prev;	
};
typedef struct Node* Nodeptr;

void push(Nodeptr* head, int data){
	if(!*head){
		return;
	}
	Nodeptr temp = (Nodeptr)malloc(sizeof(struct Node));
	temp->data = data;
	temp->next = (*head)->next;
	temp->prev = *head;
	(*head)->next->prev = temp;
	(*head)->next = temp;
}
void pop(Nodeptr *head){
	if(!*head || !(*head)->next){
		return;
	}
	Nodeptr temp = (*head)->next;
	(*head)->next = temp->next;
	temp->next->prev = *head;
	free(temp);
}
void print(Nodeptr head){
	Nodeptr temp = head->next;
	while(temp!=head){
		printf("%d",temp->data);
		temp = temp->next;
	}
}
Nodeptr add(Nodeptr head1, Nodeptr head2){

	if(!head1 && !head2){
		return NULL;
	}

	if(!head1){
		return head2;
	}

	if(!head2){
		return head2;
	}

	Nodeptr head = (Nodeptr)malloc(sizeof(struct Node));
	head->next = head->prev = head;

	int carry = 0,data;

	Nodeptr temp1 = head1->prev, temp2 = head2->prev;

	while(temp1!=head1 && temp2!=head2){

		data = temp1->data + temp2->data + carry;

		if(data >= 10){
			carry = 1;
			data -= 10;
			push(&head,data);
		}
		else{
			carry = 0;
			push(&head,data);
		}

		temp1 = temp1->prev;
		temp2 = temp2->prev;
	}
	while(temp1!=head1){

		data = temp1->data + carry;

		if(data >= 10){
			carry = 1;
			data -= 10;
			push(&head,data);
		}
		else{
			carry = 0;
			push(&head,data);
		}
		temp1 = temp1->prev;
	}
	while(temp2!=head2){

		data = temp2->data + carry;

		if(data >= 10){
			carry = 1;
			data -= 10;
			push(&head,data);
		}
		else{
			carry = 0;
			push(&head,data);
		}
		temp2 = temp2->prev;
	}
	if(carry > 0){
		push(&head,carry);
	}
	return head;
}
int main(){
	Nodeptr head1 = (Nodeptr)malloc(sizeof(struct Node));
	head1->next = head1->prev = head1;
	Nodeptr head2 = (Nodeptr)malloc(sizeof(struct Node));
	head2->next = head2->prev = head2;
	push(&head2,4);
	push(&head2,9);
	push(&head2,1);
	Nodeptr head3 = add(head1,head2);
	print(head3);
	printf("\n");
	return 0;
}