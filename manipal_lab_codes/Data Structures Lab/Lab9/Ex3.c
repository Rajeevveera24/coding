#include <stdio.h> 
struct Node 
{ 
	char string [30]; 
	struct Node *next; 
	struct Node *prev;     
}; 
void reverse(struct Node **head_ref) 
{ 
	struct Node *temp = NULL;   
	struct Node *current = *head_ref; 
	while (current !=  NULL) 
	{ 
		temp = current->prev; 
		current->prev = current->next; 
		current->next = temp;               
		current = current->prev; 
	}       
	if(temp != NULL ) 
	*head_ref = temp->prev; 
}      
void push(struct Node** head_ref, char new_string[]) 
{ 
	struct Node* new_node = (struct Node*) malloc(sizeof(struct Node)); 
	strcpy(new_node->string,new_string);
	new_node->prev = NULL; 
	new_node->next = (*head_ref);     
	if((*head_ref) !=  NULL) {
		(*head_ref)->prev = new_node ;     
	}
	(*head_ref)    = new_node; 
}
void printList(struct Node *node) 
{ 
	while(node!=NULL) 
	{ 
		printf("%s\t", node->string); 
		node = node->next; 
	} 
}  
int main() 
{ 
	struct Node* head = NULL;
	int option;
	char string[30];
	printf("Enter the words\n");
	do{
		printf("Enter String: \n");
		gets(string);
		gets(string);
		push(&head,string);
		printf("Enter 0 to go to next stage. Enter any other key to continue\n");
		scanf("%d",&option);
	}while(option!=0);
	printf("Linked List:\t");
	printList(head);
	reverse(&head);
	printf("\nReversed Linked list:\t"); 
	printList(head);        
	return 0;    
} 