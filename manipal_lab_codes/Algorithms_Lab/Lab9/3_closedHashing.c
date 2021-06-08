#include <stdio.h>

#define MAX 100

int hashTable[MAX], size;

int hash(int data){
	return data%size;
}

void insert(int data){
	int pos = hash(data);
	for(int i= pos; i<size; i++){
		if(hashTable[i] == data){
			return;
		}
		if(hashTable[i] == -1){
			hashTable[i] = data;
			return;
		}
	}
	printf("Can't fit in hash table\n");	
}

void search(int data){
	int count = 0, i = hash(data);
	for(; i<size; i++){
		if(hashTable[i] == data){
			printf("Search Successful\nValue found in position %d\n", i);
			count++;
			printf("Key Comparisons: %d\n", count);
			return;
		}
		count++;
	}
	printf("Search Unsuccessful\nKey Comparisons: %d\n", count);
}

int main(){
	int data, choice;
	printf("Enter the size of the hash table: ");
	scanf("%d", &size);
	for(int i=0; i<size; i++){
		hashTable[i] = -1;
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
				printf("Index\tValue\n");
				for(int i=0; i<size; i++){
					printf("%d\t%d\n", i, hashTable[i]);
				}
				break;
			}
			default:{
				printf("Enter valid option\n");
			}
		}
	}while(choice!=0);
}