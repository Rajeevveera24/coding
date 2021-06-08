#include<stdio.h>
#include<stdlib.h>
struct Node
{
	int data;
	struct Node *left,*right;
};
typedef struct Node* Nodeptr;

void insert_iter(Nodeptr *root,int data){

	Nodeptr temp = (Nodeptr)malloc(sizeof(struct Node));
	temp->data = data;
	temp->left = temp->right = NULL;

	if(!*root){
		*root = temp;
		return;
	}

	Nodeptr cur = *root;

	while(cur){
		if(cur->data == data){
			printf("Duplicates not allowed in BST\n");
			free(temp);
			return;
		}
		if(data<cur->data){
			if(cur->left){
				cur = cur->left;
			}
			else{
				cur->left  = temp;
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
void preorder_rec(Nodeptr root){
	if(root){
		printf("%d  ",root->data);
		preorder_rec(root->left);
		preorder_rec(root->right);
	}
}
void inorder_rec(Nodeptr root){
	if(root){
		inorder_rec(root->left);
		printf("%d  ",root->data);
		inorder_rec(root->right);
	}
}
void postorder_rec(Nodeptr root){
	if(root){
		postorder_rec(root->left);
		postorder_rec(root->right);
		printf("%d  ",root->data);
	}
}
Nodeptr delete(Nodeptr root,int data){
	if(!root){
		printf("Tree is empty\n");
		return NULL;
	}
	Nodeptr cur,suc,q,prev;
	cur = root;
	prev = NULL;
	while(cur && cur->data!=data){
		prev = cur;
		if(data < cur->data){
			cur = cur->left;
		}
		else{
			cur = cur->right;
		}
	}
	if(!cur){
		printf("Element not found in tree\n");
		return NULL;
	}
	if(!cur->left){
		q = cur->right;
	}
	else if(!cur->right){
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
	if(!prev){
		return q;
	}
	if(cur == prev->left){
		prev->left = q;
	}
	else{
		prev->right = q;
	}
	free(cur);
	return root;
}
Nodeptr inorder_successor(Nodeptr root,Nodeptr temp){

	if(temp->right){
		temp = temp->right;
		while(temp->left){
			temp = temp->left;
		}
		return temp;
	}

	Nodeptr cur = root;
	Nodeptr prev = NULL;

	while(cur!=temp){
		if(cur->left == temp){
			return cur;
		}
		if(cur->data < temp->data){
			cur = cur->right;
		}
		else{
			prev = cur;
			cur = cur->left;
		}
	}
	return prev;
}
Nodeptr find_node(Nodeptr root, int data){
	Nodeptr temp = root;
	while(temp){
		if(data == temp->data){
			return temp;
		}
		if(data < temp->data){
			temp = temp->left;
		}
		else{
			temp = temp->right;
		}
	}
	return NULL;
}
int main(){
	Nodeptr root = NULL;
	int data,option;
	do{
		printf("*******************MENU*******************\n");
		printf("1)Insert new Node\n2)Delete a Node\n3)Display Tree\n4)Find inorder successor of a Node\n5)Exit\nChoice: ");
		scanf("%d",&option);
		if(option == 5){
			break;
		}
		switch(option){
			case 1:{
				printf("Enter the element to be inserted: ");
				scanf("%d",&data);
				insert_iter(&root,data);
			}
			break;
			case 2:{
				printf("Enter the element to be Deleted: ");
				scanf("%d",&data);
				root = delete(root,data);
			}
			break;
			case 3:{
				printf("\t\t******MENU******\n");
				printf("\t\t1)Preorder\n\t\t2)inorder\n\t\t3)Postorder\n\t\tChoice: ");
				scanf("%d",&option);
				if(option == 1){
					printf("\t\t");
					preorder_rec(root);
					printf("\n");
				}
				else if(option == 2){
					printf("\t\t");
					inorder_rec(root);
					printf("\n");
				}
				else if(option == 3){
					printf("\t\t");
					postorder_rec(root);
					printf("\n");
				}
				else{
					printf("\t\tEnter proper choice next Time\n");
				}

			}
			break;
			case 4:{
				printf("Enter the element whose inorder successor has to be found: ");
				scanf("%d",&data);
				Nodeptr temp = find_node(root,data);
				if(!temp){
					printf("Node doesn't exist in tree\n");
					continue;
				}
				temp = inorder_successor(root,temp);
				if(!temp){
					printf("Inorder successor not found\n");
				}
				else{
					printf("Inorder successor is %d\n",temp->data);
				}
			}
			break;
			default:{
				printf("Enter any one of the given choices only\n");
			}
		}
	}while(1);
	return 0;
}