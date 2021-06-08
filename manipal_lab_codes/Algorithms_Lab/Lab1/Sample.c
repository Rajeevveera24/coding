#include <stdio.h>
#include <stdlib.h>

struct node{
	int val;
	struct node *lLINK,*rLink;
};

typedef struct node *NODE;

NODE head = NULL;

void createList(int val){
	
	if (head){
		printf("List has already been created\n");
	}
	else{
		NODE nd = (NODE)malloc(sizeof(struct node));
		nd->lLINK = nd->rLink = NULL;
		nd->val = val;
		head = nd;
	}
}

void insertIntoList(int before, int val){
	
	NODE nd,newnd;
	nd = head;

	while(nd->val != before){
		nd = nd->rLink;
	}

	if(nd != NULL){
		newnd = (NODE)malloc(sizeof(struct node));
		newnd->val = val;

		if(nd->lLINK !=NULL){
			nd->lLINK->rLink = newnd;
			newnd->lLINK = nd->lLINK;
			newnd->rLink = nd;
			nd->lLINK = newnd;
		}
		else{
			newnd->rLink = nd;
			nd->lLINK = newnd;
			head = newnd;
		}
	}
	else{
		printf("Value not found in the list\n");
	}
}

void deleteVal(int val){
	NODE nd = head;

	while(nd != NULL){
		
		if(nd->val = val){
			
			if(nd->lLINK != NULL){
				
				nd->lLINK->rLink = nd->rLink;

				if(nd->rLink != NULL){
					nd->rLink->lLINK = nd->lLINK;
					nd = nd->rLink;
				}
				else{
					nd->lLINK = nd->rLink = NULL;
					nd = NULL;
				}
			}
			else{
				if(nd->rLink != NULL){
					nd->rLink->lLINK = NULL;
					head = nd->rLink;
					free(nd);
					nd = head;
				}
				else{
					free(nd);
					head = nd =NULL;
				}
			}
		}
		else{
			nd = nd->rLink;
		}
	}
}

void searchNode(int val){
	NODE nd = head;
	short int flag = 0;
	
	while(nd != NULL){
		if(nd->val == val){
			printf("Node with search key value %d was found\n",val);
			flag = 1;
			break;
		}
		nd = nd->rLink;
	}

	if(flag == 0){
		printf("No node found with given search key value\n");
	}
}

void displayList(){
	NODE nd = head;
	while(nd != NULL){
		printf("%d\t",nd->val);
		nd = nd->rLink;
	}
}

int main(){

	int choice, val, before;

	do{
		printf("\n===================================MENU=========================================\n\n");
		printf("1. Create List\n");
		printf("2. Insert into List\n");
		printf("3. Search a key value\n");
		printf("4. Delete all by key values\n");
		printf("5. Display all node values\n");
		printf("6. Exit program\n");
		printf("\n Enter your Choice:\t");

		scanf("%d",&choice);

		switch(choice){

			case 1:{
				printf("\nEnter the node value:\t");
				scanf("%d",&val);
				createList(val);
			}
			break;

			case 2:{
				printf("\nEnter the node value to be inserted:\t");
				scanf("%d",&val);
				printf("Enter the value of the node before which the current node has to be inserted:\t");
				scanf("%d",&before);
				insertIntoList(before,val);
			}
			break;

			case 3:{
				printf("\nEnter the node value to be searched:\t");
				scanf("%d",&val);
				searchNode(val);
			}
			break;

			case 4:{
				printf("\nEnter the node value to be deleted:\t");
				scanf("%d",&val);
				deleteVal(val);
			}
			break;

			case 5:{
				printf("\nDisplaying List....\n");
				displayList();
			}
			break;

			case 6:{
				printf("\nGoodbye....\n");
			}
			break;

			default:{
				printf("\nInvalide choice. Please enter a different choice next time....\n");
			}
			break;
		}
	}while(choice != 6);

	return 0;
}
