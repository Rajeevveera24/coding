#include <stdio.h> 
#include <stdlib.h>
#include "binary_search_tree.h"

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
	printf("Pre order traversal of tree is:\t\t");
	preorder_rec(root);
	printf("\n");
	printf("In order traversal of tree is:\t\t");
	inorder_rec(root);
	printf("\n");
	printf("Post order traversal of tree is:\t");
	postorder_rec(root);
	printf("\n");
	return 0;
}