#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int numP, qCount=0;
short int gant[500];

typedef struct {
	int id, aTime, bTime, pri, wTime, rTime,  sTime, fTime;
}process;
process p[MAX], q[MAX];

void enQueue(process p){
	q[qCount++] = p;
	process temp;
	for(int i=0; i<qCount; i++){
		for(int j=0; j<qCount-i-1; j++){
			if(q[j].pri > q[j+1].pri){
				temp = q[j];
				q[j] = q[j+1];
				q[j+1] = temp;
			}
		}
	}
}

void deQueue(){
	for(int i=0; i<numP; i++){
		if(q[0].id == p[i].id){
			p[i] = q[0];
			break;
		}
	}
	qCount--;
	for(int i=0; i<qCount; i++){
		q[i] = q[i+1];
	}
}

void prePri(int totalTime){
	int time = 0;
	while(time < totalTime){
		for(int i=0; i<numP; i++){
			if(p[i].aTime == time){
				enQueue(p[i]);
			}
		}
		gant[time] = q[0].id;
		if(q[0].sTime == -1){
			q[0].sTime = time;
			printf("Process %d started at %d\n", q[0].id, time);
		}
		q[0].rTime--;
		for(int i=1; i<qCount; i++){
			q[i].wTime++;
		}
		if(q[0].rTime == 0){
			q[0].fTime = time;
			printf("Process %d finished at %d\n", q[0].id, time);
			deQueue();
		}
		time++;
	}
}

void showGant(int totalTime){
	for(int i=0 ;i<totalTime; i++){
		printf("time: %d\t\t process: %d\n", i, gant[i]);
	}
}

void showProcess(){
	int wt = 0;
	printf("\nID\tarrival\tstart\tfinsih\twait\tpriority\n");
	for(int i=0; i<numP; i++){
		printf("%d\t%d\t%d\t%d\t%d\t%d\n", p[i].id, p[i].aTime, p[i].sTime, p[i].fTime, p[i].wTime, p[i].pri);
		wt += p[i].wTime;
	}
	printf("\nAverage waiting time is %0.2f\n", (float)(wt/numP));
}

int main(){
	scanf("%d", &numP);
	int totalTime = 0;
	for(int i=0; i<numP; i++){
		scanf("%d %d %d %d", &p[i].id, &p[i].aTime, &p[i].bTime, &p[i].pri);
		p[i].wTime = 0;
		p[i].rTime = p[i].bTime;
		totalTime += p[i].bTime;
		p[i].sTime = -1;
	}
	prePri(totalTime);
	showGant(totalTime);
	showProcess();
	return 0;
}