#include<stdio.h>
#include<string.h>
struct Node 
{
	char data;
	struct Node * next;	
};
void printList (struct Node *node) 
{ 
    while (node != NULL) 
    { 
        printf ("%c ", node->data); 
        node = node->next; 
    } 
} 
void push(struct Node** head_ref, char new_data) 
{ 
    /* allocate node */
    struct Node* new_node = (struct Node* ) malloc(sizeof(struct Node)); 
              
    /* put in the data  */
    new_node->data  = new_data;      
          
    /* move the head to point to the new node */
    struct Node* temp = *head_ref;
    while(temp!=NULL){
    	temp = temp->next;
    }
    temp = new_node; 
} 
char pop(struct Node **head){
	if(*head==NULL){
		exit(1);
	}
	struct Node*temp = *head;
	while(temp->next!=NULL){
		temp = temp->next;
	}
	char ret = temp->data;
	free(temp);
	return ret;
}
int main(){
	char x[30];
	gets(x);
	struct Node * stack,*exp;
	char op1,op2;
	stack = NULL;
	exp = NULL;
	for(int i=0;i<strlen(x);i++){
		char a = x[i];
		if(a>=65 && a<=90 || a>=97 && a<=122){
			push(&stack,a);
			printList(stack);
		}
		else{
			op2 = pop(&stack);
			op1 = pop(&stack);
			push(&exp,op2);
			push(&exp,a);
			push(&exp,op1);
		}
	}
	printList(exp);
	return 0;
}