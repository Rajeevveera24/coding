#include <stdio.h> 
#include <stdlib.h>
#include "binary_search_tree.h"

void displayBalanceAll(Nodeptr root);
int findBalance(Nodeptr root);
int findHeight(Nodeptr root);
int max(int, int);

int main(){
	Nodeptr root = NULL;
	int num, choice = 1;
	do{
		printf("Enter 1 to create a node and 0 to stop: ");
		scanf("%d", &choice);
		switch(choice){
			case 0:
				break;
			case 1:{
				printf("Enter value of node: ");
				scanf("%d", &num);
				insert_iter(&root, num);
			}
		}	
	}while(choice != 0);
	printf("Level order traversal of tree is:\t");
	levelorder(root);
	printf("\n");
	printf("In order traversal of tree is:\t\t");
	inorder_rec(root);
	printf("\n");
	displayBalanceAll(root);
	return 0;
}

void displayBalanceAll(Nodeptr root){
	if(root){
		printf("Balance factor of node %d is %d\n", root->data, findBalance(root));
		displayBalanceAll(root->left);
		displayBalanceAll(root->right);
	}
}

int findBalance(Nodeptr root){
	if(!root){
		return 0;
	}
	return (findHeight(root->left) - findHeight(root->right));
}

int findHeight(Nodeptr root){
	if(!root){
		return 0;
	}
	return (1 + max(findHeight(root->left), findHeight(root->right)));
}

int max(int a, int b){
	return a>b?a:b;
}