#include <stdio.h>
#include <stdlib.h>
#include "binary_tree_functions.h"

int max3(int, int, int);
int max2(int, int);
int findDiameter(Nodeptr root);
int findHeight(Nodeptr root);

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
	printf("Diameter of tree is %d\n", findDiameter(root));
	return 0;
}

int findDiameter(Nodeptr root){
	if(!root){
		return 0;
	}
	return max3(findDiameter(root->left), findDiameter(root->right), (1 + findHeight(root->left) + findHeight(root->right)));
}
int findHeight(Nodeptr root){
	if(!root){
		return 0;
	}
	return (1 + max2(findHeight(root->left), findHeight(root->right)));
}

int max3(int a, int b, int c){
	return (a>b?(a>c?a:c):(b>c?b:c));
}

int max2(int a, int b){
	return (a>b?a:b);
}