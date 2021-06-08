#include <stdio.h>

int abs(int a);
int fcfs(int req[], int numReq, int *head);
int sstf(int req[], int numReq, int *head);
int findShortestValue(int req[], int numReq, int done[], int *head);
int scan(int req[], int numReq, int *head);
void bubbleSort(int a[], int size);
int cscan(int req[], int numReq, int *head);

int main(int argc, char const *argv[]){
	int request[30], numReq, head;
	printf("Enter the number of requests: ");
	scanf("%d", &numReq);
	printf("Enter the requests\n");
	for (int i=0; i<numReq; i++){
		scanf("%d", &request[i]);
	}
	printf("Enter the current position of head: ");
	scanf("%d", &head);
	int pos = head;
	printf("Number of cylinder movements using FCFS is %d\n", fcfs(request, numReq, &head));
	head = pos;
	printf("Number of cylinder movements using SSTF is %d\n", sstf(request, numReq, &head));
	head = pos;
	printf("Number of cylinder movements using SCAN is %d\n", scan(request, numReq, &head));
	head = pos;
	printf("Number of cylinder movements using CSCAN is %d\n", cscan(request, numReq, &head));
	return 0;
}

int fcfs(int req[], int numReq, int *head){	//Works...
	int count = abs(req[0] - *head);
	*head = req[0];
	for(int i=1; i<numReq; i++){
		count += abs(req[i] - *head);
		*head = req[i];
	}
	return count;
}

int sstf(int req[], int numReq, int *head){	//Works...
	int count = 0, temp = 0;
	int done[numReq];
	for(int i=0 ;i<numReq; i++){
		done[i] = 0;
	}
	while(temp < numReq){
		count += findShortestValue(req, numReq, done, head);
		temp++;
	}
	return count;
}

int findShortestValue(int req[], int numReq, int done[], int *head){	//Works...
	int shortestValue = 1000, shortestPos = -1; //arbitrarily large value...

	for(int i=0; i<numReq; i++){
		if(done[i] == 0){
			if(abs(req[i] - *head) < shortestValue){
				shortestValue = abs(req[i] - *head); 
				shortestPos = i;
			}
		}
	}
	if(shortestPos != -1){
		*head = req[shortestPos];
		done[shortestPos] = 1;
		return shortestValue; 
	}
	return 0;
}

int scan(int req[], int numReq, int *head){	//Works...
	int count = 0, pos, temp[numReq];
	for(int i=0; i<numReq; i++){
		temp[i] = req[i];
	}
	bubbleSort(temp, numReq);

	for(int i=0; i<numReq; i++){
		if(*head < temp[i]){
			pos = i;
			break;
		}
	}
	for(int i=pos-1; i>=0; i--){
		count += abs(*head - temp[i]);
		*head = temp[i];
	}
	count += *head - 0;
	*head = 0;
	for(int i=pos; i<numReq; i++){
		count += abs(*head - temp[i]);
		*head = temp[i];
	}
	return count;
}

void bubbleSort(int a[], int size){
	for(int i=0; i<size; i++){
		for(int j=0; j<size-i-1; j++){
			if(a[j] > a[j+1]){
				a[j] += a[j+1];
				a[j+1] = a[j] - a[j+1];
				a[j] -= a[j+1];
			}
		}
	}
}

int cscan( int req[], int numReq, int *head){
	int count = 0, pos, temp[numReq];
	for(int i=0; i<numReq; i++){
		temp[i] = req[i];
	}
	bubbleSort(temp, numReq);

	for(int i=0; i<numReq; i++){
		if(*head < temp[i]){
			pos = i;
			break;
		}
	}

	for(int i=pos; i<numReq; i++){
		count += abs(*head - temp[i]);
		*head = temp[i];
	}
	count += abs(*head - 199);
	//*head = 199; 	//	Redundant assignment - Meant only to give a feel of simulation of CSCAN...
	*head = 0;

	for(int i=0; i<pos; i++){
		count += abs(*head - temp[i]);
		*head = temp[i];
	}
	
	return count;
}

int abs(int a){		//Works...
	return a>0?a:(-1*a);
}