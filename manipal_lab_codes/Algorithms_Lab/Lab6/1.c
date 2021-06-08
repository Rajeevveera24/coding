#include <stdio.h> 
#include <stdlib.h>
#include "binary_tree_functions.h"

int opCount = 0;

int findNumberNodes(Nodeptr root);

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
	printf("Level order traversal of tree is: ");
	levelorder(root);
	printf("\n");
	printf("Number of nodes in tree is %d\n", findNumberNodes(root));
	printf("Operation count is %d\n",opCount);
	return 0;
}

int findNumberNodes(Nodeptr root){
	opCount++;
	if(!root){
		return 0;
	}
	return (1 + findNumberNodes(root->left) + findNumberNodes(root->right));
}