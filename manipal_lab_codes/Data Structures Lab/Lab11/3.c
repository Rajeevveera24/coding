//Adding header files...
#include<stdio.h>
#include<stdlib.h>
#include"binary_search_tree.h"//This file contains all the required functions...

Nodeptr inorder_successor(Nodeptr root, Nodeptr node){

	if(node->right){
		node = node->right;
		while(node->left){
			node = node->left;
		}
		return node;
	}

	Nodeptr par = NULL;
	Nodeptr cur = root;

	while(cur!=node){
		if(cur->left == node){
			return cur;
		}

		if(cur->data < node->data){
			cur = cur->right;
		}
		else{
			par = cur;
			cur = cur->left;
		}
	}

	return par;
}

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
	//Done creating the BST...

	/*
	//For debugging purposes only...
		insert_iter(&root,4);
		insert_iter(&root,2);
		insert_iter(&root,6);
		insert_iter(&root,1);
		insert_iter(&root,3);
		insert_iter(&root,5);
		insert_iter(&root,7);
	*/
	printf("Enter the element whose inorder successor has to be found\n");
	scanf("%d",&data);

	Nodeptr node = NULL;
	Nodeptr cur = root;
	//Finding the node whose inorder successor has to be found...
	while(cur){
		if(cur->data == data){//Node is found...
			node = cur;
			break;
		}
		if(data < cur->data){
			cur = cur->left;
		}
		else{
			cur = cur->right;
		}
	}

	if(!node){//If the node hasn't been found, no such element exists in the BST...
		printf("Element not found in tree\n");
		exit(0);
	}

	node = inorder_successor(root,node);

	if(!node){//If the node is the maximal element in the BST, it will have no inorder successor...
		printf("Element has no inorder successor\n");
		exit(0);
	}

	printf("Inorder successor of element is %d\n",node->data);

	return 0;
}