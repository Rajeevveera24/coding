#include <stdio.h>
#include <stdlib.h>

struct process{
	int arrTime, burTime, remTime;
	//int priority;
};
typedef struct process pro;

void srjf(pro *, int);
//void bubbleSort(pro*, int);
int selectShort(pro*, int);
int sumBurstTime(pro*, int);

int main(){
	int numP;
	pro* p;

	printf("Enter the number of processes: ");
	scanf("%d", &numP);

	p = (pro*)malloc(numP * sizeof(pro));

	printf("Enter the arrival times and burst Time for each process side by side:\n");
	for(int i=0; i<numP; i++){
		scanf("%d %d", &(p[i].arrTime), &(p[i].burTime));
		p[i].remTime = p[i].burTime;
	}

	srjf(p, numP);

	return 0;
}

void srjf(pro p[], int size){
	
	int countP = 1, currentP, *wt, *tt, awt, att;

	//bubbleSort(p, size); //sorting the processes based on arrival time, on the assumption that no two processes arrive at the exact same time...

	currentP = 0;

	printf("Starting...\n");
	//printf("Executing process %d\n", currentP);

	for(int t=0; t<sumBurstTime(p, size); t++){	//Start the simulation, and run till all current process have been executed...

		if(p[countP].arrTime == t){//if a new process has arrived at the current time...

			p[countP].remTime = p[countP].burTime;
			
			if(p[countP].remTime < p[currentP].remTime){	//if remaining time of new process is lesser than current one, start the new process...
				currentP = countP;
				printf("Switching to process %d at time %d\n", currentP+1, t);
			}

			countP++;	//process counter increased...
		}

		printf("Executing process %d at %d\n",currentP+1, t+1);
		p[currentP].remTime -= 1;

		if(p[currentP].remTime == 0){	//if current process has finished execution...
			printf("Process %d has finished execution at time %d. ", currentP+1, t+1);
			currentP = selectShort(p, size);
			printf("Switching to process %d\n", currentP+1);
		}
	}
}

int selectShort(pro p[], int size){
	int min = 0;

	while(p[min].remTime == 0 && min < size){
		min++;
	}
	for(int i=0; i<size; i++){
		if(p[i].remTime == 0){
			continue;
		}
		if(p[i].remTime < p[min].remTime){
			min = i;
		}
	}

	return min;
}

int sumBurstTime(pro *p, int size){
	int sum = 0;
	for(int i=0; i<size; i++){
		sum += p[i].burTime;
	}
	return sum;
}