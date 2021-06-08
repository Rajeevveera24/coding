#include<stdio.h>
#include<stdlib.h>

struct Node{
	int digit;
	struct Node* next;
	struct Node* prev;
};

void push(struct Node ** head_ref, int digit);//Add to end of list...
void print(struct Node* head);//Prints the list from front to rear...
void add(struct Node** head_ref_add, struct Node* head_ref1, struct Node* head_ref2);//Adds two numbers...

//Main Function...
int main(){

	int digit;
	struct Node* head_num1 = (struct Node*)malloc(sizeof(struct Node));
	head_num1->prev = head_num1->next = head_num1;
	struct Node* head_num2 = (struct Node*)malloc(sizeof(struct Node));
	head_num2->prev = head_num2->next = head_num2;
	struct Node* head_add;

	printf("Enter the 0th place digit in the first number\n");
	scanf("%d",&digit);
	push(&head_num1,digit);
	for(;;){
		printf("Enter the digit in next 10ths place. Enter any negative number to go to next stage\n");
		scanf("%d",&digit);
		if(digit<0 || digit>=10){
			break;
		}
		else{
			push(&head_num1,digit);
		}
		digit = -1;//In order to avoid an infinite loop...
	}

	printf("Enter the 0th place digit in the second number\n");
	scanf("%d",&digit);
	push(&head_num2,digit);
	for(;;){
		printf("Enter the digit in next 10ths place. Enter any negative number to go to next stage\n");
		scanf("%d",&digit);
		if(digit<0 || digit>=10){
			break;
		}
		else{
			push(&head_num2,digit);
		}
		digit = -1;//In order to avoid an infinite loop...
	}

	printf("First number is ");
	print(head_num1);
	printf("\n");

	printf("Second number is ");
	print(head_num2);
	printf("\n");

	add(&head_add,head_num1,head_num2);
	printf("Sum of the two numbers is ");
	print(head_add);
	printf("\n");

	return 0;
}

//Function to insert at end of the list...
void push(struct Node ** head_ref, int digit){

	if ((*head_ref)->next == NULL) {

		struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
		new_node->digit = digit;
		new_node->next = new_node->prev = *head_ref;
		(*head_ref)->next = (*head_ref)->prev = new_node; 
		return; 
	} 

	struct Node *last = (*head_ref)->prev;

	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
	new_node->digit = digit; 
	new_node->next = *head_ref;
	new_node->prev = last;

	(*head_ref)->prev = new_node; 
	last->next = new_node; 
}

//Function to print the data in all the nodes, starting from the front of the list...
void print(struct Node* head){
	struct Node* temp = head;
	while(temp->prev!=head){
		temp = temp->prev;
		printf("%d",temp->digit);
	}
}

//Function to add two numbers...
void add(struct Node** head_ref_add, struct Node* head_num1, struct Node* head_num2){

	struct Node* num1 = head_num1;
	struct Node* num2 = head_num2;
	struct Node* add = (struct Node*)malloc(sizeof(struct Node));
	add->prev = add->next = add;
	int carry=0,digit;

	while(num1->next!=head_num1 && num2->next!=head_num2){
		num1 = num1->next;
		num2 = num2->next;
		digit = num1->digit + num2->digit + carry;
		if(digit>=10){
			digit %= 10;
			carry = 1;
		}
		else{
			carry = 0;
		}
		push(&add,digit);
	}

	while(num1->next!=head_num1){
		num1=num1->next;
		digit = num1->digit + carry;
		if(digit>=10){
			digit %= 10;
			carry = 1;
		}
		else{
			carry = 0;
		}
		push(&add,digit);
	}

	while(num2->next!=head_num2){
		num2=num2->next;
		digit = num2->digit + carry;
		if(digit>=10){
			digit %= 10;
			carry = 1;
		}
		else{
			carry = 0;
		}
		push(&add,digit);
	}

	if(carry){
		push(&add,carry);
	}

	(*head_ref_add) = add;
}