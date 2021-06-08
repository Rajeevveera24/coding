#include <stdio.h>

#define MAX 20

int allocation[MAX][MAX], need[MAX][MAX], max[MAX][MAX], availabe[MAX];
int n,m;

void bankers(){
	int work[m], finish[n];
	for(int i=0; i<n; i++){
		finish[i] = 0;
	}
	for(int i=0; i<m; i++){
		work[i] = availabe[i];
	}
	for(int i=0; i<n; i++){
		if(!finish[i]){
			int flag = 1;
			for(int j=0; j<m; j++){
				if(need[i][j] > work[j]){
					flag = 0; 
				}
			}
			if(flag){
				for(int j=0; j<m; j++){
					work[j] += allocation[i][j];
				}
				finish[i] = 1;
				printf("%d done\n", i);
				i=-1;
			}
		}
	}
	int flag = 1;
	for(int i=0; i<n ;i++){
		flag = flag & finish[i];
	}
	if(flag){
		printf("Safe\n");
	}
	else{
		printf("Unsafe\n");
	}
}

int main(){
	scanf("%d %d", &n, &m);
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			scanf("%d", &max[i][j]);
		}
	}
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			scanf("%d", &allocation[i][j]);
			need[i][j] = max[i][j] - allocation[i][j];
		}
	}
	for(int i=0; i<m; i++){
		scanf("%d", &availabe[i]);
	}
	bankers();
}
