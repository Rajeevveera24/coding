#include <stdio.h>
#include <stdlib.h>

struct process{
	int arrTime, burTime, remTime;
	//int priority;
};
typedef struct process pro;

void rr(pro *, int, int);


int main(){
	int numP, q;
	pro* p;

	printf("Enter the number of processes: ");
	scanf("%d", &numP);

	p = (pro*)calloc(numP, sizeof(pro));

	printf("Enter the arrival times and burst Time for each process side by side:\n");
	for(int i=0; i<numP; i++){
		scanf("%d %d", &(p[i].arrTime), &(p[i].burTime));
		p[i].remTime = p[i].burTime;
	}
	printf("Enter the time quantum: ");
	scanf("%d", &q);

	srjf(p, numP);

	return 0;
}