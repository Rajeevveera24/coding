//This file contains functions that are used in BTs only; All functions common to both BTs and BSTs 
//can be found in "binary_tree_utilities.h"...

//Including header file(s)...
#include"binary_tree_utilities.h" // This file includes all the utility functions common to BSTs and Binary Trees...


//Function Declarations...
void insert_iter(Nodeptr* root_ref,int data);
Nodeptr delete_node(Nodeptr root,int data);


//Function Defenitions...

//This function iteratively inserts an element in a binary search tree...
void insert_iter(Nodeptr* root_ref, int data){
	Nodeptr cur  = *root_ref;
	Nodeptr temp = (struct Node*)malloc(sizeof(struct Node));
	temp->data = data;
	temp->left = temp->right = NULL;

	if(!(*root_ref)){
		*root_ref = temp;
		return;
	}

	while(cur){
		if(cur->data == data){
			printf("Duplicates not allowed in BST\n");
			free(temp);
			return;
		}
		if(data < cur->data){
			if(cur->left){
				cur = cur->left;
			}
			else{
				cur->left = temp;
				break;
			}
		}
		else{
			if(cur->right){
				cur = cur->right;
			}
			else{
				cur->right = temp;
				break;
			}
		}
	}
}
//End of function...

//This function deletes a node with given data, while maintaining all the nodes of the binary tree in proper fashion...
Nodeptr delete_node(Nodeptr root, int data){

	Nodeptr par,suc,q,cur;

	if(root == NULL){
		printf("Tree is empty\n");
		return root;
	}

	par = NULL;
	cur = root;

	while((cur!=NULL) && (data!=cur->data)){
		par = cur;
		if(data < cur->data){
			cur = cur->left;
		}
		else{
			cur = cur->right;
		}
	}

	if(!cur){
		printf("Element not found\n");
		return root;
	}
	
	if(cur->left == NULL){
		q = cur->right;
	}
	else if(cur->right == NULL){
		q = cur->left;
	}
	else{
		suc = cur->right;

		while(suc->left){
			suc = suc->left;
		}

		suc->left = cur->left;
		q = cur->right;
	}

	if(par == NULL){
		return q; 
	}

	if(cur == par->left){
		par->left = q;
	}
	else{
		par->right = q;
	}	
	
	free(cur);
	return root;
}
//End of Function...
