#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node *left,*right;
};
typedef struct Node* Nodeptr;

void insert_rec(Nodeptr *root_ref,int data){
	if(!*root_ref){
		Nodeptr temp = (Nodeptr)malloc(sizeof(struct Node));
		temp->data = data;
		temp->left = temp->right = NULL;
		*root_ref = temp;
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

void inorder_rec(Nodeptr root){
	if(root){
		inorder_rec(root->left);
		printf("%d  ",root->data);
		inorder_rec(root->right);
	}
}

void create_mirror(Nodeptr root, Nodeptr* mirror){
	if(root){
		Nodeptr temp = (Nodeptr)malloc(sizeof(struct Node));
		temp->data = root->data;
		*mirror = temp;

		create_mirror(root->left,&((*mirror)->right));
		create_mirror(root->right,&((*mirror)->left));
	}
}

int main(){
	Nodeptr root  = NULL;
	Nodeptr mirror = NULL;
	int data,option;
	do{
		printf("******************MENU**********************\n");
		printf("1)Insert\n2)Display tree\n3)Display Mirror\n4)Exit\nChoice: ");
		scanf("%d",&option);
		if(option == 4){
			break;
		}
		switch(option){
			case 1:{
				printf("Enter the element to be Inserted: ");
				scanf("%d",&data);
				insert_rec(&root,data);
			}
			break;
			case 2:{
				inorder_rec(root);
				printf("\n");
			}
			break;
			case 3:{
				create_mirror(root,&mirror);
				inorder_rec(mirror);
				printf("\n");
			}
			break;
			default:{
				printf("Enter proper choice\n");
			}
			break;
		}
	}while(1);
}