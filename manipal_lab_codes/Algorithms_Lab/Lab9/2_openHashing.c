#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Node{
	int data;
	struct Node* next;
};

struct Node* HashTable[MAX];
int size, n, m;

int hash(int data){
	return data%size;
}

void insert(int data){
	n++;
	int pos = hash(data);
	struct Node* temp = HashTable[pos];
	if(temp == NULL){
		temp = (struct Node*)malloc(sizeof(struct Node));
		temp->data = data;
		temp->next = NULL;
		HashTable[pos] = temp;
		//free(temp);
		return;
	}
	while(temp->next != NULL){
		if(temp->data == data || temp->next->data == data){
			n--;
			return;
		}
		temp = temp->next;
	}
	temp->next = (struct Node*)malloc(sizeof(struct Node));
	temp->next->data = data;
	temp->next->next = NULL;	
}

void search(int data){
	int count = 0, i = hash(data);
	struct Node* temp = HashTable[i];
	while(temp!=NULL){
		if(temp->data == data){
			count++;
			printf("Successful Search\nKey Comparisons: %d\n", count);
			return;
		}
		count++;
		temp = temp->next;
	}
	printf("Search Unsuccessful\nKey Comparisons: %d\n", count);
}

void printTable(){
	struct Node* temp;
	printf("Index\tValue(s)\n");
	for(int i=0; i<size; i++){
		printf("%d\t", i);
		temp = HashTable[i];
		if(temp == NULL){
			printf("\n");
			continue;
		}
		while(temp->next!=NULL){
			printf("%d\t", temp->data);
			temp = temp->next;
 		}
		printf("%d\n", temp->data);
	}
	printf("Total number of elements, n = %d\nLoad Factor = %d\n", n, n/size);
}

int main(){
	int data, choice;
	printf("Enter the size of the hash table: ");
	scanf("%d", &size);
	m = size;
	for(int i=0; i<size; i++){
		HashTable[i] = NULL;
	}
	printf("Enter 0,1,2,3 to exit, enter, search and display hash table respectively\n");
	do{
		printf("Enter choice: ");
		scanf("%d", &choice);
		switch(choice){
			case 0:
			break;
			case 1:{
				printf("Enter the value of element: ");
				scanf("%d", &data);
				insert(data);
				break;
			}
			case 2:{
				printf("Enter the element to be found: ");
				scanf("%d", &data);
				search(data);
				break;
			}
			case 3:{
				printTable();
				break;
			}
			default:{
				printf("Enter valid option\n");
			}
		}
	}while(choice!=0);
	return 0;
}




