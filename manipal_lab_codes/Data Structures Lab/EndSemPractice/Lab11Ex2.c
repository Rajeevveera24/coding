#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

struct Node{
	char data;
	struct Node *left,*right;
};
typedef struct Node* Nodeptr;

typedef struct StackNode{
	Nodeptr node;
	struct StackNode *next;
};

void push(struct StackNode **top_ref, Nodeptr node){
	struct StackNode* temp = (struct StackNode*)malloc(sizeof(struct StackNode));

	temp->node = node;
	temp->next = *top_ref;
	*top_ref = temp;
}
Nodeptr pop(struct StackNode** top_ref){
	Nodeptr temp;
	struct StackNode* top;
	if(*top_ref){

		top = *top_ref;
		temp = top->node;
		*top_ref = top->next;
		free(top);
		return temp;

	}
}
Nodeptr create_postfix_tree(char postfix[]){
	
	Nodeptr temp;
	struct StackNode* stack = NULL;
	int i=0;
	char symbol;

	for(int i=strlen(postfix)-1;i>=0;i--){
		symbol = postfix[i];

		temp = (Nodeptr)malloc(sizeof(struct Node));
		temp->data = symbol;
		temp->left = temp->right = NULL;

		if(isalnum(symbol)){
			push(&stack,temp);
		}
		else{
			temp->left = pop(&stack);
			temp->right = pop(&stack);
			push(&stack,temp);
		}
	}
	return pop(&stack);
}

float eval_postfix(Nodeptr root){

	switch(root->data){
		case '+': return (eval_postfix(root->left) + eval_postfix(root->right));
		break;
		case '-': return (eval_postfix(root->left) - eval_postfix(root->right));
		break;
		case '*': return(eval_postfix(root->left) * eval_postfix(root->right));
		break;
		case '/': return(eval_postfix(root->left) / eval_postfix(root->right));
		break;
		//case '$':
		//case '^': return(pow(eval_postfix(root->left), eval_postfix(root->right)));
		//break;
		default: return (root->data - '0');
	}
}

int main(){
	char *postfix;
	printf("Enter the prefix expression\n");
	scanf("%s",postfix);
	Nodeptr root = create_postfix_tree(postfix);
	printf("The final answer is %0.2f\n",eval_postfix(root));
	return 0;
}