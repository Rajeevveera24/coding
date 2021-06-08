#include <stdio.h>
#include <stdlib.h>

void fcfs(int *, int*, int);

int main(){
	int *arrTime, *burTime, numP;

	printf("Enter the number of processes: ");
	scanf("%d", &numP);

	arrTime = (int*)calloc(numP, sizeof(int));
	burTime = (int*)calloc(numP, sizeof(int));

	printf("Enter the arrival times and burst Time for each process side by side:\n");
	for(int i=0; i<numP; i++){
		scanf("%d %d", &arrTime[i], &burTime[i]);
	}

	fcfs(arrTime, burTime, numP);

	return 0;
}

void fcfs(int *arr, int *bur, int size){
	int awt = 0, att = 0, *pStart = (int*)calloc(size, sizeof(int)), *pFinish = (int*)calloc(size, sizeof(int));

	pStart[0] = arr[0];
	pFinish[0] = bur[0];

	for(int i=1; i<size; i++){
		pStart[i] = pFinish[i-1];
		pFinish[i] = pStart[i] + bur[i]; 
	}

	printf("Gant Chart is as follows\n");

	printf("Process\t\tArrival Time\tStart Time\tFinish Time\tWaiting Time\tTurn Around Time\n");

	for(int i=0; i<size; i++){
		printf("%d\t\t", i+1);
		printf("%d\t\t", arr[i]);
		printf("%d\t\t", pStart[i]);
		printf("%d\t\t", pFinish[i]);
		awt += pStart[i] - arr[i];
		printf("%d\t\t", pStart[i] - arr[i]);
		att += pFinish[i] - arr[i];
		printf("%d\n", pFinish[i] - arr[i]);
	}

	awt /= size;
	att /= size;

	printf("\nAverage waiting time is %d and average turn around time is %d\n\n", awt, att);
}
