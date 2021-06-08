/* NOTE - This file contains definitions of those functions which are common to both BSTs and BTs such as 
	traversals.
	Functions like insertion and deletion are NOT defined here, as they are different for BTs and BSTs.

	Also, the basic structural definition of a Node (any node of a BST/BT) is given here, along with the
	structure definitions of structures required to maintain a queue,stack of nodes etc...
*/


//Structure Defenitions...

//Node - Each node stores an integer value and has a left sub node and a right sub node...
struct Node{
	int data;
	struct Node* left;
	struct Node* right;
};
typedef struct Node* Nodeptr;

//This is a utility structure defines a stack of nodes, with each node being a node in a binary tree...
struct StackNode 
{ 
  int flag;//Variable flag is only used in certain functions, such as iterative post order traversal, etc...
  struct Node *t; 
  struct StackNode *next; 
};

//QNode & Queue - used by functions like level order traversal etc...
struct QNode{
	Nodeptr node;
	struct QNode* next;
};

struct Queue 
{ 
    struct QNode *front, *rear; 
}; 

//End of structure Defenitions...


//Function declarations...

//Utility Functions...
void push(struct StackNode** top_ref, struct Node *t); 
void push_with_flag(struct StackNode** top_ref, struct Node *t, int flag);
struct Node *pop(struct StackNode** top_ref);
int isEmpty(struct StackNode *top);

void insert_queue(struct Queue* queue, Nodeptr node);
Nodeptr delete_queue(struct Queue* queue);

//Functions common to both BSTs and BTs...
void inorder_iter(Nodeptr root);
void preorder_iter(Nodeptr root);
void postorder_iter(Nodeptr root);
void inorder_rec(Nodeptr root);
void preorder_rec(Nodeptr root);
void postorder_rec(Nodeptr root);
void levelorder(Nodeptr root);

//End of function declarations...


//Start of function definitions...

//Start of Utility Function Definitions...

//This is a utility function to push elements onto a stack of Node Pointers...
void push(struct StackNode** top_ref, struct Node *t){

	struct StackNode* new_Node = (struct StackNode*) malloc(sizeof(struct StackNode)); 

	if(new_Node == NULL) {//If we run out of memory to create a new StackNode... 
		printf("Stack Overflow\n"); 
		return;
	}             
	new_Node->t  = t; 
	/* link the old list off the new Node */
	new_Node->next = (*top_ref);
	/* move the head to point to the new Node */
	(*top_ref) = new_Node; 
}
//End of function...

//This functions pops and returns the top node of StackNode...
struct Node* pop(struct StackNode** top_ref){

	struct Node *res; 
	struct StackNode *top; 

	if(isEmpty(*top_ref)) //If the top node is empty...
	{ 
		printf("Stack Underflow \n"); 
		exit(0);
	} 
	top = *top_ref; 
	res = top->t; 
	*top_ref = top->next; 
	free(top); 
	return res; 
}
//End of function...

//This function returns 1 (true) if the stack is empty and 0 (false) if the stack is not...
int isEmpty(struct StackNode* top){
	return (top == NULL)?1:0;
}
//End of function...

//This is a utility function to push elements onto a stack of Node Pointers. It has the added feature of being able to modify the flag...
void push_with_flag(struct StackNode** top_ref, struct Node *t, int flag){

	struct StackNode* new_Node = (struct StackNode*) malloc(sizeof(struct StackNode)); 

	if(new_Node == NULL) {//If we run out of memory to create a new StackNode... 
		printf("Stack Overflow\n"); 
		return;
	}             
	new_Node->t  = t; 
	new_Node->flag = flag;
	/* link the old list off the new Node */
	new_Node->next = (*top_ref);
	/* move the head to point to the new Node */
	(*top_ref) = new_Node; 
}
//End of function...

//This function is used to insert a node to the end (rear) of a queue of nodes...
void insert_queue(struct Queue* queue, Nodeptr node){

    struct QNode *temp = (struct QNode*)malloc(sizeof(struct QNode));
    temp->node = node;
    temp->next = NULL;
 
    if(queue->rear == NULL){ 
       queue->front = queue->rear = temp; 
       return; 
    } 

    queue->rear->next = temp;
    queue->rear = temp;
}
//End of function...

//This function is used to delete a node from the beginning (front) of a queue of nodes...
Nodeptr delete_queue(struct Queue* queue){

    if(queue->front == NULL){ 
       return NULL;
   	}

    struct QNode *temp = queue->front; 
    queue->front = queue->front->next; 
   
    if(queue->front == NULL){
       	queue->rear = NULL;
    }
    return temp->node; 
}
//End of function...

//End of Utility function definitions...

//Start of definitions of functions common to both BTs and BSTs...

//This function iteratively traverses and prints the elements of the tree in inorder fashion...
void inorder_iter(Nodeptr root){

	if(!root){//If root is NULL...
		return;
	}
	struct Node* cur = root;
	struct StackNode* stack = NULL;  
	for(;;){
		while(cur){
			push(&stack,cur);
			cur = cur->left;
		}
		if(!isEmpty(stack)){
			cur = pop(&stack);
			printf("%d  ",cur->data);
			cur = cur->right;
		}
		else{
			return;
		}
	}
}
//End of function...

//This function iteratively traverses the tree and prints the elements in preorder fashion...
void preorder_iter(Nodeptr root){
	
	if(!root){
		return;
	}

	struct Node* cur = root;
	struct StackNode* stack = NULL;
	for(;;){
		while(cur){
			printf("%d  ",cur->data);
			push(&stack,cur);
			cur = cur->left;
		}
		if(!isEmpty(stack)){
			cur = pop(&stack);
			cur = cur->right;
		}
		else{
			return;
		}
	}
}
//End of Function...

//This function iteratively traverses the tree and prints the elements in postorder fashion...
void postorder_iter(Nodeptr root){
	if(root){
		struct Node* cur = root;
		struct StackNode* stack = NULL;
		for(;;){
			while(cur){
				push_with_flag(&stack,cur,1);
				cur = cur->left;
			}
			while(stack->flag<0){
				cur = pop(&stack);
				printf("%d  ",cur->data);
				if(isEmpty(stack)){
					return;
				}
			}
			cur = stack->t;
			cur = cur->right;
			stack->flag = -1;
		}
	}
}
//End of function...

//This function recursively traverses and prints the elements of the tree in inorder fashion...
void inorder_rec(Nodeptr root){
	if(root){
		inorder_rec(root->left);
		printf("%d  ",root->data);
		inorder_rec(root->right);
	}
}
//End of function...

//This function recursively traverses and prints the elements of the tree in preorder fashion...
void preorder_rec(Nodeptr root){
	if(root){//If root is not NULL
		printf("%d  ",root->data);
		preorder_rec(root->left);
		preorder_rec(root->right);
	}
}
//End of function...

//This function recursively traverses and prints the elements of the tree in postorder fashion...
void postorder_rec(Nodeptr root){
	if(root){//If root is not NULL
		postorder_rec(root->left);
		postorder_rec(root->right);
		printf("%d  ",root->data);
	}
}
//End of function...

//This function traverses the tree in levelorder fashion and prints the elements...
void levelorder(Nodeptr root){

	struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
	queue->front = queue->rear = NULL; 

	insert_queue(queue,root);
	//printf("Reached here\n");
	Nodeptr cur;
	while(1){//Entering a controlled infinite loop...

		cur = delete_queue(queue);

		if(cur == NULL){//If cur is NULL, it implies that the queue is empty indicating that we have traversed all the nodes...
			break;
		}

		printf("%d  ",cur->data);

		if(cur->left){
			insert_queue(queue,cur->left);
		}
		if(cur->right){
			insert_queue(queue,cur->right);
		}
	}
}

//End of function definitions...


//End of Code...