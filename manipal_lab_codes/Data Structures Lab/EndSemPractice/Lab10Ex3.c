#include <stdio.h>
#include <stdlib.h>

struct Node{
	int data;
	struct Node *left,*right;
};
typedef struct Node* Nodeptr;

void insert_rec(Nodeptr* root_ref, int data){
	if(!*root_ref){
		Nodeptr temp = (Nodeptr)malloc(sizeof(struct Node));
		temp->data = data;
		temp->right = temp->left = NULL;
		*root_ref  = temp;
		return;
	}
	char ch[5];
	printf("Enter Left or Right: ");
	scanf("%s",ch);
	if(ch[0] == 'L' || ch[0] == 'l'){
		insert_rec(&((*root_ref)->left),data);
	}
	else{
		insert_rec(&((*root_ref)->right),data);
	}
}
void print_left(Nodeptr root){
	if(!root->left){
		printf("%d  ",root->data);
		return;
	}
	print_left(root->left);
	printf("%d  ",root->data);
}
void print_right(Nodeptr root){
	if(!root->right){
		printf("%d  ",root->data);
		return;
	}
	printf("%d  ",root->data);
	print_right(root->right);
}
void print_topview(Nodeptr root){
	if(!root){
		return;
	}
	Nodeptr temp = root;
	if(root->left){
		print_left(root->left);
	}
	printf("%d  ",root->data);
	if(root->right){
		print_right(root->right);
	}
	printf("\n");
}
int main(){
	Nodeptr root = NULL;
	int data, option;
	do{
		printf("******************MENU**********************\n");
		printf("1)Insert\n2)Display Top View\n3)Exit\nChoice: ");
		scanf("%d",&option);
		if(option == 3){
			break;
		}
		switch(option){
			case 1:{
				printf("Enter the element to be Inserted: ");
				scanf("%d",&data);
				insert_rec(&root,data);			}
			break;
			case 2:{
				print_topview(root);
			}
			break;
			default:{
				printf("Enter proper option\n");
			}
			break;
		}
	}while(1);
	return 0;
}