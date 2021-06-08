#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node *left,*right;
};
typedef struct Node* Nodeptr;

void insert_rec(Nodeptr *root, int data){
	if(!*root){
		Nodeptr temp = (Nodeptr)malloc(sizeof(struct Node));
		temp->data = data;
		temp->left = temp->right = NULL;
		*root = temp;
		return;
	}
	char ch[5];
	printf("Enter Left or Right: ");
	scanf("%s",ch);
	if(ch[0] == 'L' || ch[0] == 'l'){
		insert_rec(&((*root)->left),data);
	}
	else{
		insert_rec(&((*root)->right),data);
	}
}
void insert_iter(Nodeptr *root, int data){
	Nodeptr temp = (Nodeptr)malloc(sizeof(struct Node));
	temp->data = data;
	temp->left = temp->right = NULL;

	if(!*root){
		*root = temp;
		return;
	}
	Nodeptr cur = *root;
	while(cur){
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
void getmax(Nodeptr root, int* max){
	if(root){
		if(root->data > *max){
			*max = root->data;
		}
		getmax(root->left,max);
		getmax(root->right,max);
	}
}
int is_bst(Nodeptr root){

	if(!root){
		return 1;
	}
	int max = root->data;
	if(root->left){
		getmax(root->left,&max);
		if(max > root->data){
			return 0;
		}
	}
	max = root->data;
	if(root->right){
		getmax(root->right,&max);
		if(root->data > max){
			return 0;
		}
	}
	if((!is_bst(root->left)) || (!is_bst(root->right))){
		return 0;
	}
	return 1;
}
int main(){
	Nodeptr root1 = NULL,root2 = NULL;
	insert_iter(&root1,4);
	insert_iter(&root1,6);
	insert_iter(&root1,1);
	insert_iter(&root1,99);
	insert_iter(&root1,-1);
	insert_rec(&root2,4);
	insert_rec(&root2,6);
	insert_rec(&root2,2);
	printf("%d\n",is_bst(root2));
	return 0;
}