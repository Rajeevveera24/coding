#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>//This file is included in order to use the functions isalnum()...
#include"binary_tree_utilities.h"

Nodeptr create_postfix_tree(char postfix[]){
	
	Nodeptr temp;
	struct StackNode* stack = NULL;
	int i=0;
	char symbol;

	while((symbol=postfix[i++])!='\0'){
		
		temp = (Nodeptr)malloc(sizeof(struct Node));
		temp->data = symbol;
		temp->left = temp->right = NULL;

		if(isalnum(symbol)){
			push(&stack,temp);
		}
		else{
			temp->right = pop(&stack);
			temp->left = pop(&stack);
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
	char postfix[30];
	printf("Enter the postfix expression\n");
	scanf("%s",postfix);
	Nodeptr root = create_postfix_tree(postfix);
	printf("The final answer is %0.2f\n",eval_postfix(root));
	return 0;
}