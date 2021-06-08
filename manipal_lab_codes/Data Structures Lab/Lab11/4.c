#include<stdio.h>
#include<stdlib.h>
#include"binary_tree_functions.h"

int printAncestors(Nodeptr root, int target) 
{ 
	if (root == NULL){ 
		return 0;
	}

	if (root->data == target){
		return 1;
	}

	if ( printAncestors(root->left, target) || printAncestors(root->right, target) ) 
	{ 
		printf("%d  ",root->data);
		return 1; 
	} 
	return 0; 
}

int main(){

	Nodeptr root = NULL;
	int data,option;

	for(;;){

		printf("Enter 1 to insert next element in the binary tree. Enter any other key to stop inserting elements.\n");
		scanf("%d",&option);

		if(option!=1){
			break;
		}

		printf("Enter element\n");
		scanf("%d",&data);

		insert_iter(&root,data);
		option = 0;//To avoid uncontrolled infinite looping...
	}
	printf("Enter the key element whose ancestors are to be printed\n");
	scanf("%d",&data);

	if(!printAncestors(root,data)){
		printf("element does not have any ancestors\n");
	}

	return 0;
}