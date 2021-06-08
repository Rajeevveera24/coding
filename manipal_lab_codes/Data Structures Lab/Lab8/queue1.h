typedef struct Node
{
	int data;
	struct Node* next;
};
void enqueue(struct Node** head_ref, int data){
	struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
	struct Node *last = *head_ref; 
	new_node->data = data;
	new_node->next = NULL;
	if(*head_ref == NULL){
		*head_ref = new_node;
		return;
	}
	while(last->next!=NULL){
		last=last->next;
	}
	last->next = new_node;
	return;
}
void dequeue(struct Node **head_ref){
	if(*head_ref == NULL){
		printf("Queue Empty\n");
		return;
	}
	struct Node *cur = *head_ref;
	*head_ref = cur->next;
	free(cur); 
}
void printq(struct Node *head) 
{ 
	if(head == NULL){
		printf("Queue Empty\n");
		return;
	}
    while (head!=NULL) 
    { 
        printf("%d ", head->data); 
        head = head->next; 
    }
    printf("\n");
}
void printlist(struct Node *head) 
{ 
	if(head == NULL){
		printf("Queue Empty\n");
		return;
	}
	struct Node*temp = head;
	do{
		printf("%d",temp->data);
		temp = temp->next;
	}while(temp!=head);
    printf("\n");
}
struct Node* addtoEmpty(struct Node* last, int data)
{
	if(last!=NULL){return last;}
	struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
	temp->data = data;
	last=temp;
	last->next=last;
	return last;
}
struct Node* addToEnd(struct Node *last, int data){
	if(last==NULL){
		return addtoEmpty(last,data);
	}
	struct Node *temp = (struct Node*),malloc(sizeof(struct Node));
	temp->data = data;
	temp->next = last->next;
	last->next=temp;
	last = temp;
	return last;
}
	
