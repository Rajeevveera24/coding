#include <stdio.h>
#include <stdlib.h>
#include "fifo.h"
#include "lru.h"

//#define MAX 100


int main(int argc, char const *argv[]){
	int qSize, numPage, *requestArray;

	printf("Enter the capacity of page queue: ");
	scanf("%d", &qSize);
	
	printf("Enter the number of page requests: ");
	scanf("%d", &numPage);
	
	requestArray = (int*)calloc(numPage, sizeof(int));
	printf("Enter the order of the requests\n");
	for(int i=0 ;i<numPage; i++){
		scanf("%d", &requestArray[i]);
	}

	simulateLRU(qSize, numPage, requestArray);

	return 0;
}