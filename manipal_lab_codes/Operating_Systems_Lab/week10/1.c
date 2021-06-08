#include <stdio.h>
#include <stdlib.h>

#define MAX 10000

typedef struct{
	int size, allocated, free, pNum; 
}memSeg;

typedef struct{
	int size, allocated;
}process;

void firstFit(memSeg m[],  process p[], int numSeg, int numProc);
void bestFit(memSeg m[], process p[], int numSeg, int numProc);
void worstFit(memSeg m[], process p[], int numSeg, int numProc);
void display(memSeg m[],  process p[], int numSeg, int numProc);

int main(int argc, char const *argv[]){
	memSeg* m;
	process *p;
	int numSeg, numProc, choice;

	printf("Enter the number of memory segments: ");
	scanf("%d", &numSeg);
	m = (memSeg*)malloc(sizeof(memSeg) * numSeg);
	printf("Enter the size of each memory segment: ");
	for(int i=0; i<numSeg; i++){
		scanf("%d", &m[i].size);
		m[i].allocated = 0;
		m[i].pNum = -1;
		m[i].free = m[i].size - m[i].allocated;
	}

	printf("Enter the number of processes: ");
	scanf("%d", &numProc);
	p = (process*)malloc(sizeof(process) * numProc);
	printf("Enter the size of each process: ");
	for(int i=0; i<numProc; i++){
		scanf("%d", &p[i].size);
		p[i].allocated = 0; 
	}
	//firstFit(m, p, numSeg, numProc);
	//bestFit(m, p, numSeg, numProc);
	//worstFit(m, p, numSeg, numProc);
	printf("Select the memory management algorithm:\t1)First Fit\t2)Best Fit\t3)Worst Fit\nEnter your choice: ");
	scanf("%d", &choice);
	switch(choice){
		case 1:{
			firstFit(m, p, numSeg, numProc);
			break;
		}
		case 2:{
			bestFit(m , p, numSeg, numProc);
			break;
		}
		case 3:{
			worstFit(m, p, numSeg, numProc);
			break;
		}
		default:{
			printf("Enter valid option next time\n");
		}
	}
	display(m, p, numSeg, numProc);
	return 0;
}

void firstFit(memSeg m[],  process p[], int numSeg, int numProc){
	for(int i=0; i<numProc; i++){
		for(int j=0; j<numSeg; j++){
			if(m[j].pNum == -1 && m[j].size >= p[i].size && p[i].allocated == 0){
				m[j].allocated = p[i].size;
				m[j].free = m[j].size - m[j].allocated;
				m[j].pNum = i;
				p[i].allocated = 1;
				break;
			}	
		}
	}
}

void bestFit(memSeg m[], process p[], int numSeg, int numProc){
	
	int small, pos;

	for(int i=0; i<numProc; i++){
		small = MAX;
		pos = -1;
		for(int j=0; j<numSeg; j++){
			if(p[i].allocated != 0){
				break;
			}
			if(m[j].pNum == -1 && m[j].size < small && m[j].size >= p[i].size){
				pos = j;
				small = m[j].size;
			}
		}
		if(pos != -1){
			m[pos].pNum = i;
			m[pos].allocated = p[i].size;
			m[pos].free = m[pos].size - m[pos].allocated;
			p[i].allocated = 1;
		}
	}
}

void worstFit(memSeg m[], process p[], int numSeg, int numProc){
	
	int big, pos;

	for(int i=0; i<numProc; i++){
		big = 0;
		pos = -1;
		for(int j=0; j<numSeg; j++){
			if(p[i].allocated != 0){
				break;
			}
			if(m[j].pNum == -1 && m[j].size > big && m[j].size >= p[i].size){
				pos = j;
				big = m[j].size;
			}
		}
		if(pos != -1){
			m[pos].pNum = i;
			m[pos].allocated = p[i].size;
			m[pos].free = m[pos].size - m[pos].allocated;
			p[i].allocated = 1;
		}
	}
}

void display(memSeg m[],  process p[], int numSeg, int numProc){
	
	printf("Process\tSize\tAllocated ?\n");
	for(int i=0; i<numProc; i++){
		printf("%d\t%d\t", i, p[i].size);
		if(p[i].allocated == 0){
			printf("No\n");
		}
		else{
			printf("Yes\n");
		}
	}

	printf("Segment Number\tTotal Space\tAllocated Space\tFree Space\tAllocated Process\n");
	for(int i=0; i<numSeg; i++){
		printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", i, m[i].size, m[i].allocated, m[i].free, m[i].pNum);
	}
	
	int count = 0;
	printf("Unallocated process Number(s):\t");
	for(int i=0; i<numProc; i++){
		if(p[i].allocated == 0){
			printf("%d\t", i);
			count++;
		}
	}
	if(count == 0){
		printf("None");
	}
	
	printf("\n");
}