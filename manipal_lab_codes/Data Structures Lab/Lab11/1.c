//Adding header files...
#include<stdio.h>
#include<stdlib.h>
#include"binary_search_tree.h"//This file contains all the required functions...

//Start of Main...
int main(){

	Nodeptr root = NULL;
	int option,data;

	//Inputting data from user to create the binary search tree...
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
	//Done creating the binary search tree...

	//Inputting element to be deleted and deleting the element...
	printf("Enter the element to be deleted\n");
	scanf("%d",&data);
	root = delete_node(root,data);

	//Displaying tree in level order fashion after deleting the node specified by user...
	printf("Elements in levelorder fashion are:\t");
	levelorder(root);
	printf("\n");
	
	return 0;
}
//End of Main...

//End of Code...