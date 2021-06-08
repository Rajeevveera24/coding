#include <stdio.h>
#include <stdlib.h>
#include "binary_tree_utilities.h"

Nodeptr initNode(int val);
Nodeptr insert_rec(Nodeptr root, int val);
Nodeptr rotateLeft(Nodeptr root);
Nodeptr rotateRight(Nodeptr root);
int findBalance(Nodeptr root);
int findHeight(Nodeptr root);
int max(int, int);

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
				root = insert_rec(root, num);
			}
		}	
	}while(choice != 0);

	printf("Level order traversal of tree is:\t");
	levelorder(root);
	printf("\n");
	printf("In order traversal of tree is:\t\t");
	inorder_rec(root);
	printf("\n");
	printf("Pre order traversal of tree is:\t\t");
	preorder_rec(root);
	printf("\n");
	printf("Post order traversal of tree is:\t");
	postorder_rec(root);
	printf("\n");

	return 0;
}

Nodeptr initNode(int val){
	Nodeptr root = (Nodeptr)malloc(sizeof(struct Node));
	root->data = val;
	root->height = 1;
	root->left = root->right = NULL;
	return root;
}

Nodeptr rotateLeft(Nodeptr root){
	Nodeptr r = root->right;
	Nodeptr rl = r->left;
	r->left = root;
	root->right = rl;

	root->height = max(findHeight(root->left), findHeight(root->right)) + 1;
	r->height = findHeight(r);

	return r;
}

Nodeptr rotateRight(Nodeptr root){
	Nodeptr l = root->left;
	Nodeptr lr = l->right;
	l->right = root;
	root->left = lr;

	root->height = max(findHeight(root->left), findHeight(root->right)) + 1;
	l->height = max(findHeight(l->left), findHeight(l->right)) + 1;

	return l;
}

Nodeptr insert_rec(Nodeptr root, int val){
	if(!root){
		return initNode(val);
	}
	if(val < root->data){
		root->left = insert_rec(root->left, val);
	}
	else if(val > root->data){
		root->right = insert_rec(root->right, val);
	}
	else{
		printf("Duplicate values are not allowed in an AVL tree\n");
		return root;
	}
	root->height = findHeight(root);
	int bal = findBalance(root);
	
	if(bal > 1){
		if(val > root->left->data){
			root->left = rotateLeft(root->left);
		}
		return rotateRight(root);
	}
	if(bal < -1){
		if(val < root->right->data){
			root->right = rotateRight(root->right);
		}
		return rotateLeft(root);
	}
	return root;
}

int findBalance(Nodeptr root){
	if(!root){
		return 0;
	}
	return (findHeight(root->left) - findHeight(root->right));
}

int findHeight(Nodeptr root){
	if(!root){
		return 0;
	}
	return (1 + max(findHeight(root->left), findHeight(root->right)));
}

int max(int a, int b){
	return a>b?a:b;
}