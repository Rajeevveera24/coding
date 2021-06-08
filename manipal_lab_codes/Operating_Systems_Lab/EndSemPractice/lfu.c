#include <stdio.h>

#define MAX 100

int numF, numR, req[MAX]; 

typedef struct{
	int val, count; 
}frame;	

frame f[MAX/2];

int isPresent(int val){
	for(int i=0; i<numF; i++){
		if(f[i].val == val){
			f[i].count++;
			return 1;
		}
	}
	return 0;
}

void replace(int val){
	int min = 0;
	for(int i=0; i<numF; i++){
		if(f[i].count < f[min].count){
			min = i;
		}
	}
	printf("Page %d replaced by page %d\n", f[min].val, val);
	for(int i=min; i<numF-1; i++){
		f[i] = f[i+1];
	}
	f[numF-1].val = val;
	f[numF-1].count = 1;
	// f[min].val = val;
	// f[min].count = 1;
}

void lfu(){
	for(int i=0; i<numF; i++){
		f[i].val = -1;
		f[i].count = -1; //f[i].count = -1 for LRU
	}
	int hit = 0, miss = 0;
	for(int i=0; i<numR; i++){
		if(isPresent(req[i])){
			hit++;
			printf("Page %d found in cache\n", req[i]);
			// continue;
		}
		else{
			miss++;
			replace(req[i]);
			// printf("Page %d added to cache\n", req[i]);
		}
	}
	printf("\nPage hits: %d\t\tPage misses: %d\n", hit, miss);
}

void replaceM(int val){
	int max = numF-1;
	for(int i=numF; i>=0; i--){
		if(f[i].count > f[max].count){
			max = i;
		}
	}
	printf("Page %d replaced by page %d\n", f[max].val, val);
	for(int i=max; i<numF-1; i++){
		f[i] = f[i+1];
	}
	f[numF-1].val = val;
	f[numF-1].count = 1;
	// f[min].val = val;
	// f[min].count = 1;
}

void mfu(){
	for(int i=0; i<numF; i++){
		f[i].val = -1;
		f[i].count = MAX; //f[i].count = -1 for LRU
	}
	int hit = 0, miss = 0;
	for(int i=0; i<numR; i++){
		if(isPresent(req[i])){
			hit++;
			printf("Page %d found in cache\n", req[i]);
			// continue;
		}
		else{
			miss++;
			replaceM(req[i]);
			// printf("Page %d added to cache\n", req[i]);
		}
	}
	printf("\nPage hits: %d\t\tPage misses: %d\n", hit, miss);
}

int main(){
	scanf("%d %d", &numF, &numR);
	for(int i=0; i<numR; i++){
		scanf("%d", &req[i]);
	}
	// lfu();
	mfu();
}