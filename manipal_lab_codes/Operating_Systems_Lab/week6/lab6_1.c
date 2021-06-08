#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>

void FCFS(int n,int data[][n],int size){
	int avgWT = 0,avgTT=0,sumBT=0,wt[size],tat[size];
	wt[0] = 0;
	for(int i=1;i<size;i++){
		sumBT += data[i-1][1];
		wt[i] = (sumBT - data[i][0]);
		avgWT += wt[i];
	}
	tat[0] = data[0][1];
	for(int i=0;i<size;i++){
		tat[i]=data[i][1]+wt[i];
		avgTT+=tat[i];
	}
	printf("Process\tBurst time\tWaiting time\tTurnaround time\n");
	for(int i=0;i<size;i++){
		printf("   %d\t\t%d\t\t%d\t\t%d\n",i+1,data[i][1],wt[i],tat[i]);
	}
	printf("Average Waiting Time is %f\n",(float)avgWT/(float)size);
	printf("Average Turnaround Time is %f\n",(float)avgTT/(float)size);
}

void RR(int n,int data[][n],int size){
	int rem_bt[size],avgWT=0,avgTT=0,wt[size],t=0,quantum = 10,tat[size]; 
    for (int i = 0 ; i < size ; i++) 
        rem_bt[i] =  data[i][1]; 
    while (1) 
    { 
        bool done = true; 
        for (int i = 0 ; i < size; i++) 
        { 
            if (rem_bt[i] > 0) 
            { 
                done = false;  
                if (rem_bt[i] > quantum) 
                { 
                    t += quantum; 
  
                    rem_bt[i] -= quantum; 
                } 
                else
                { 
                    t = t + rem_bt[i]; 
                    wt[i] = t - data[i][1]- data[i][0]; 
                    rem_bt[i] = 0; 
                } 
            } 
        } 
        if (done == true) 
          break; 
    } 
    for (int i = 0; i < size ; i++){ 
        tat[i] = (data[i][1] + wt[i]); 
        avgTT += tat[i];
    	avgWT += wt[i];	
    }
    printf("Process\tBurst time\tWaiting time\tTurnaround time\n");
	for(int i=0;i<size;i++){
		printf("   %d\t\t%d\t\t%d\t\t%d\n",i+1,data[i][1],wt[i],tat[i]);
	}
    printf("Average Waiting Time is %f\n",(float)avgWT/(float)size);
	printf("Average Turnaround Time is %f\n",(float)avgTT/(float)size);
}

void SRTF(int n,int data[][n],int size){
	int rt[size],avgWT=0,avgTT=0,wt[size],tat[size]; 
    for (int i = 0; i < size; i++) 
        rt[i] = data[i][1]; 
  
    int complete = 0, t = 0, minm = INT_MAX; 
    int shortest = 0, finish_time; 
    bool check = false; 
    while (complete != size) { 
        for (int j = 0; j < size; j++) { 
            if ((data[j][0] <= t) && 
            (rt[j] < minm) && rt[j] > 0) { 
                minm = rt[j]; 
                shortest = j; 
                check = true; 
            } 
        } 
  
        if (check == false) { 
            t++; 
            continue; 
        } 
        rt[shortest]--; 
        minm = rt[shortest]; 
        if (minm == 0) 
            minm = INT_MAX; 
        if (rt[shortest] == 0) { 
            complete++; 
            check = false; 
            finish_time = t + 1; 
            wt[shortest] = finish_time - 
                        data[shortest][1] - 
                        data[shortest][0]; 
  
            if (wt[shortest] < 0) 
                wt[shortest] = 0; 
        } 
        t++; 
    } 

    for (int i = 0; i < size ; i++){ 
        tat[i] = (data[i][1] + wt[i]); 
        avgTT += tat[i];
    	avgWT += wt[i];	
    }
    printf("Process\tBurst time\tWaiting time\tTurnaround time\n");
	for(int i=0;i<size;i++){
		printf("   %d\t\t%d\t\t%d\t\t%d\n",i+1,data[i][1],wt[i],tat[i]);
	}
    printf("Average Waiting Time is %f\n",(float)avgWT/(float)size);
	printf("Average Turnaround Time is %f\n",(float)avgTT/(float)size);
}

int main(){
	int n;
	printf("Enter number of processes : \n");
	scanf("%d",&n);
	int data[n][3];
	printf("Enter arrival time of processes : ");
	for(int i=0;i<n;i++){
		scanf("%d",&data[i][0]);
	}
	printf("Enter burst time of processes : ");
	for(int i=0;i<n;i++){
		scanf("%d",&data[i][1]);
	}
	printf("Enter priority of processes : ");
	for(int i=0;i<n;i++){
		scanf("%d",&data[i][2]);
	}
	int choice;
	while(1){
		printf("Choose \n1.FCFS\n2.SRTF\n3.Round - Robin(quantum = 10)\n-1.Exit\n");
		scanf("%d",&choice);
		switch(choice){
			case 1: {
				FCFS(3,data,n);
				break;
			}
			case 2: {
				SRTF(3,data,n);
				break;
			}
			case 3: {
				RR(3,data,n);
				break;
			}
			case -1: {
				printf("Exiting");
				exit(0);
			}
			default: {
				printf("Invalid input\nPlease enter value again\n");
				break;
			}
		}
	}
}