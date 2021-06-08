int q[10];

void deleteFIFO(int size){
	for(int i=0; i<size-1; i++){
		q[i] = q[i+1];
	}
}

void insertFIFO(int num, int *pos, int size){
	if(*pos == size-1){
		deleteFIFO(size);
		q[*pos] = num;
	}
	else{
		*pos = *pos + 1;
		q[*pos] = num;
	}
}

void displayFIFO(int pos, int size){
	for(int i=0; i<= pos; i++){
		printf("%d\t", q[i]);
	}
	printf("\n");
}

int searchQueueFIFO(int pos, int num){
	for(int i=0; i<= pos; i++){
		if(num == q[i]){
			return i;
		}
	}
	return -1;
}


void simulateFifo(int qSize, int numPage, int* requestArray){
	if(qSize > 10){
		printf("Queue size has been reset to 10...\n");
		qSize = 10;
	}

	int pageHit = 0, pageMiss = 0, pos = -1;
	
	for(int i=0; i<numPage; i++){
		if(searchQueueFIFO(pos, requestArray[i]) != -1){
			pageHit++;
			//continue;
		}
		else{
			pageMiss++;
			insertFIFO(requestArray[i], &pos, qSize);		
		}
		displayFIFO(pos, qSize);
	}
	//printf("%d %d\n", f, r);
	printf("Page Hits: %d\n", pageHit);
	printf("Page Misses: %d\n", pageMiss);
}