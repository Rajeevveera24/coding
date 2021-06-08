#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
	int data;
	struct Node * next;
};
struct Node* AddtoEnd(struct Node* last,int data){
	if(last == NULL){
		struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
		temp->data = data;
		last = temp;
		last->next = last;
		return last;
	}
	struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
	temp->data = data;
	temp->next = last->next;
	last->next = temp;
	last = temp;
	return last;
}
void printList(struct Node* head){
	struct Node* temp = head;
	if(head!=NULL){
		do{
			temp = temp->next;
			printf("%d ",temp->data);
		}while(temp!=head);
	}
}
struct Node* merge(struct Node* a, struct Node* b){
	if(a==NULL && b==NULL){
		printf("Both nodes are null\n");
		return a;
	}
	struct Node *c,*last_a,*last_b;
	c = (struct Node*)malloc(sizeof(struct Node));
	last_a = a;
	last_b = b;
	a=a->next;
	b=b->next;
	c = (struct Node*)malloc(sizeof(struct Node));
	do{
		if(a->data>b->data){
			c->data = b->data;
			c=c->next;
			b = b->next;
		}
		else{
			c->data = a->data;
			c = c->next;
			a = a->next;
		}
	}while(a!=last_a && b!=last_b);
	while(a!=last_a){
			c->data = a->data;
			c = c->next;
			a = a->next;
	}
	while(b!=last_b){
		c->data = b->data;
		c=c->next;
		b = b->next;
	}
	return c;
}
int main(){
	struct Node* head = NULL;
	head = AddtoEnd(head,5);
	head = AddtoEnd(head,10);
	head = AddtoEnd(head,15);
	struct Node* head1 = NULL;
	head1 = AddtoEnd(head1,3);
	head1 = AddtoEnd(head1,17);
	struct Node *head2;
	head2 = merge(head1,head);
	printList(head2);
	return 0;
}

