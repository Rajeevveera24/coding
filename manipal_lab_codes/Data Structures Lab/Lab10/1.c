//Listing header files to be included...

#include<stdio.h>
#include<stdlib.h>//If this file in not included, compiler gives a warning. The program appears to work fine without the header file too...
#include"binary_tree_functions.h"//This file contains structure and function defenitions...

//Start of Main...

int main(){
	
	//Variable Declarations...
	struct Node* root = NULL;
	int option,data,flag;

	//Asking user to insert values into the tree...
	for(;;){//Controlled Infinite loop...
		printf("Enter 1 to insert another element in the tree and any other key to stop inserting elements.\n");
		scanf("%d",&option);
		if(option!=1){//Condition to break out of infinite loop...
			break;
		}
		printf("Enter the value of the element to be inserted\n");
		scanf("%d",&data);
		insert_rec(&root,data);
		option = 0;//Resetting value of option to avoid infinite looping in case of any 
					//unexpected events while taking option as input in nex iteration...
	}
	//Done asking user to insert values into the tree...

	//Searching for an element entered by user...
	printf("Enter the element to be searched for\n");
	scanf("%d",&data);
	flag=0;//Setting flag to 0...
	search_rec(root,data,&flag);
	if(flag){
		printf("Element found\n");
	}
	else{
		printf("Element not found\n");
	}

	//Printing out the elements of the tree...
	printf("Elements of tree in preorder fashion are:\t");
	preorder_rec(root);
	printf("\n");
	printf("Elements of tree in inorder fashion are:\t");
	inorder_iter(root);
	printf("\n");
	printf("Elements of tree in postorder fashion are:\t");
	postorder_rec(root);
	printf("\n");
	//Done printing elements of the tree...

	//Returning 0
	return 0;
}

//End of Main...


//End of Code...