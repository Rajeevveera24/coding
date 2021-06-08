#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 20

void bubbleSort(char arr[][80], int size);
void createArray(char arr[][80], unsigned int size);
void printList(char arr[][80], int size);

int main(){
	
	char arr[MAX_SIZE][80];
	unsigned int size;

	printf("\nEnter the size of the array:\t");
	scanf("%d",&size);

	createArray(arr,size);

	bubbleSort(arr,size);

	printList(arr,size);

	printf("\nGoodbye...\n\n");

	return 0;
}

void bubbleSort(char a[][80], int size){
	//int opCount = 0;

	printf("\n\nBubble sorting the strings...\n\n");

	char temp[80];
	for(int i=0;i<size;i++){
		for(int j=0;j<size-i-1;j++){
			if(strcmp(a[j],a[j+1]) > 0){
				strcpy(temp,a[j]);
				strcpy(a[j],a[j+1]);
				strcpy(a[j+1],temp);
			}
			//opCount++;
		}
	}
	//printf("\nOperation count is %d\n",opCount);
}

void createArray(char arr[][80], unsigned int size){

	printf("\nEnter the strings of the array:\t");

	for(int i=0;i<size;i++){
		scanf("%s",arr[i]);
	}
}

void printList(char arr[][80], int size){

	printf("Strings in the list are:\t");

	for(int i = 0; i<size; i++){
		printf("%s\t",arr[i]);
	}
	printf("\n");
}