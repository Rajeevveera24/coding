//Listing header files to be included...

#include<stdio.h>
#include<stdlib.h>//If this file in not included, compiler gives a warning. The program appears to work fine without this header file...
#include"binary_tree_functions.h"//This file contains structure and function defenitions...\

//Start of Main...

int main(){

	int data,option;
	Nodeptr root = NULL;

	//Inputting elements of the tree from the user...
	for(;;){

		printf("Enter 1 to insert next element in binary tree and any other key to stop inserting elements\n");
		scanf("%d",&option);

		if(option!=1){
			break;
		}

		printf("Enter value of element\n");
		scanf("%d",&data);
		insert_iter(&root,data);
		option = 0;
	}
	//Done creating the tree...

	//Printing elements of the tree...
	printf("Elements of the tree in preorder:\t");
	preorder_iter(root);
	printf("\n");
	printf("Elements of the tree in inorder:\t");
	inorder_iter(root);
	printf("\n");
	printf("Elements of the tree in postorder:\t");
	postorder_iter(root);
	printf("\n");
	//Done printing the elements of the tree...

	return 0;
}

//End of Main...


//End of Code...