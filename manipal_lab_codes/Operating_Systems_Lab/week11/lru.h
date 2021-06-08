typedef struct{
	int data, count;
}page;

page p[10];

int findmaxLRU(int size){
	int max = 0, pos = 0;
	for(int i=0; i<size; i++){
		if(max < p[i].count){
			max = p[i].count;
			pos = i;
		}
	}
	return pos;
}

void insertLRU(int size, int data, int *pos){
	if(*pos >= size-1){//replace LRU page entry
		int i = findmaxLRU(size);
		//printf("%d with count %d being replaced\n", p[i].data, p[i].count);
		p[i].count = 0;
		p[i].data = data;
		for(int j=0; j<size; j++){
			if(j!=i){
				p[j].count++;
			}
		}
	}
	else{
		*pos = *pos + 1;
		p[*pos].count = 0;
		p[*pos].data = data;
		for(int j=0; j<= *pos; j++){
			p[j].count++;
		}
	}
}

int searchQueueLRU(int pos, int num){
	for(int i=0; i<= pos; i++){
		if(num == p[i].data){
			return i;
		}
	}
	return -1;
}

void displayQueueLRU(int pos, int num){
	for(int i=0; i<= pos; i++){
		printf("%d\t", p[i].data);
	}
	printf("\n");
}

void simulateLRU(int qSize, int numPage, int *requestArray){
	int k;
	if(qSize > 10){
		printf("Queue size has been reset to 10...\n");
		qSize = 10;
	}
	int pageHit = 0, pageMiss = 0, pos = -1;
	for(int i=0; i<numPage; i++){
		if( (k = searchQueueLRU(pos, requestArray[i])) != -1){
			pageHit++;
			p[k].count = 0;
			for(int j=0; j <= pos; j++){
				if(j != k){
					p[j].count++;
				}
			}
			//printf("HIT\n");
			//continue;
		}
		else{
			pageMiss++;
			//printf("MISS\n");
			insertLRU(qSize, requestArray[i], &pos);		
		}
		displayQueueLRU(pos, qSize);
	}

	printf("Page Hits: %d\n", pageHit);
	printf("Page Misses: %d\n", pageMiss);
}