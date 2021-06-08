#include <stdio.h>
#include <stdlib.h>

struct node{
	int data, height;
	struct node *left, *right; 
}Node;

typedef struct node* Nodeptr;

Nodeptr initNode(int data){
	Nodeptr root = (Nodeptr)malloc(sizeof(Node));
	root->data = data;
	root->left = root->right = NULL;
	root->height = 1;
	return root;
}

int max(int a, int b){
	return a>b?a:b;
}

int findHeight(Nodeptr root){
	if(!root){
		return 0;
	}
	return 1 + max(findHeight(root->left), findHeight(root->right));
}

int findBalance(Nodeptr root){
	return findHeight(root->left) - findHeight(root->right);
}

Nodeptr rotateLeft(Nodeptr root){
	Nodeptr r = root->right;
	Nodeptr rl = r->left;
	root->right = rl;
	r->left = root;
	root->height = findHeight(root);
	r->height = findHeight(r);
	return r;
}

Nodeptr rotateRight(Nodeptr root){
	Nodeptr l = root->left;
	Nodeptr lr = root->left->right;
	root->left = lr;
	l->right = root;
	root->height = findHeight(root);
	l->height = findHeight(l);
	return l;
}

Nodeptr insertNode_rec(Nodeptr root, int data){
	if(!root){
		root = initNode(data);
		return root;
	}
	if(data < root->data){
		root->left = insertNode_rec(root->left, data);
	}
	else if(data > root->data){
		root->right = insertNode_rec(root->right, data);
	}
	else{
		return root;
	}
	root->height = findHeight(root);
	int bal = findBalance(root);
	if(bal > 1){
		if(data > root->left->data){
			root->left = rotateLeft(root->left);
		}
		root = rotateRight(root);
	}
	else if(bal < -1){
		if(data < root->right->data){
			root->right = rotateRight(root->right);
		}
		root = rotateLeft(root);
	}
	return root;
}

void inorder_rec(Nodeptr root){
	if(root){
		inorder_rec(root->left);
		printf("%d ",root->data);
		inorder_rec(root->right);
	}
}

void preorder_rec(Nodeptr root){
	if(root){
		printf("%d ", root->data);
		preorder_rec(root->left);
		preorder_rec(root->right);
	}
}

void postorder_rec(Nodeptr root){
	if(root){
		postorder_rec(root->left);
		postorder_rec(root->right);
		printf("%d ", root->data);
	}
}

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
				root = insertNode_rec(root, num);
			}
		}	
	}while(choice != 0);

	// printf("Level order traversal of tree is:\t");
	// levelorder(root);
	// printf("\n");
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
