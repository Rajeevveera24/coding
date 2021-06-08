#include <stdio.h>

int opCount = 0, n, G[21][21], R[21][21][21];

int min(int a, int b){
	if(a>b){
		return b;
	}
	else{
		return a;
	}
}

void floyd(){
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n;j++){
			R[0][i][j] = G[i][j];
		}
	}

	for(int k=1; k<=n; k++){
		for(int i=1; i<=n; i++){
			for(int j=1; j<=n;j++){
				R[k][i][j] = min(R[k-1][i][j], (R[k-1][i][k] + R[k-1][k][j]));
				opCount++;
			}
		}
	}
}

int main(int argc, char const *argv[]){
	//int n, G[20][20], R[21][20][20];
	printf("Enter the size of the graph (20 or lesser): ");
	scanf("%d", &n);
	printf("Enter the adjacency matrix of the graph:\n");
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n;j++){
			scanf("%d", &G[i][j]);
		}
	}
	floyd();
	printf("Cost Matrix is:\n");
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			printf("%d\t", R[n][i][j]);
		}
		printf("\n");
	}
	printf("opCount is %d\n", opCount);
	return 0;
}