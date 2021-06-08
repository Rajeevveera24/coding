//This file contains only those functions that are used in BTs, NOT in BSTs...
//To find definitions functions common to both BSTs and BTs (such as traversals), go to "binary_tree_utilities.h"... 

//Including Header files...

#include"binary_tree_utilities.h"//This file contains the structure defenitions and stack functions...

//Function declarations...
void insert_iter(struct Node** root, int data);
void insert_rec(struct Node** root, int data);
void search_rec(struct Node* root, int data, int *flag);
//End of function declarations...


//Start of Function Defenitons...

//This function  iteratively inserts elements in a binary tree...
void insert_iter(Nodeptr* root_ref, int data){
	char choice[5];
	Nodeptr cur  = *root_ref;
	Nodeptr temp = (Nodeptr)malloc(sizeof(struct Node));
	temp->data = data;
	temp->left = temp->right = NULL;

	if(!(*root_ref)){
		*root_ref = temp;
		return;
	}
	while(cur){
		printf("Enter Left or Right\n");
		scanf("%s",choice);
		if(choice[0] == 'L' || choice[0] == 'l'){
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

//This function recursively insets values into the binary tree...
void insert_rec(Nodeptr* root_ref, int data){
	if(!(*root_ref)){//If root==NULL...
		Nodeptr temp = (Nodeptr)malloc(sizeof(struct Node));
		temp->data = data;
		temp->left = temp->right = NULL;
		*root_ref = temp;
		return;
	}
	char choice[5];
	printf("Enter Left or Right\n");
	scanf("%s",choice);
	if(choice[0] == 'L' || choice[0] == 'l'){
		insert_rec(&((*root_ref)->left),data);
	}
	else{
		insert_rec(&((*root_ref)->right),data);
	}
}
//End of function... 

//This function recursively searches for an element in a tree...
void search_rec(Nodeptr root, int data, int *flag){
	if(root){//If root is not NULL...
		if(root->data == data){
			*flag=1;
			return;
		}
		search_rec(root->left,data,flag);
		if((*flag)!=1){//If flag is not equal to 1...
			search_rec(root->right,data,flag);
		}
	}
}
//End of function...

//End of Function defenitions...


//End of Code...