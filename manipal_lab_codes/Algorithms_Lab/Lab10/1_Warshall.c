#include <stdio.h>

int opCount = 0;

void warshall(int, int G[21][21], int R[21][21][21]);

int main(int argc, char const *argv[]){
	int n, G[21][21], R[21][21][21];
	printf("Enter the size of the graph (20 or lesser): ");
	scanf("%d", &n);
	printf("Enter the adjacency matrix of the graph:\n");
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n;j++){
			scanf("%d", &G[i][j]);
		}
	}
	warshall(n, G, R);
	printf("Transitive closure is:\n");
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			printf("%d\t", R[n][i][j]);
		}
		printf("\n");
	}
	printf("opCount is %d\n", opCount);
	return 0;
}

void warshall(int n, int G[21][21], int R[21][21][21]){
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n;j++){
			R[0][i][j] = G[i][j];
		}
	}

	for(int k=1; k<=n; k++){
		for(int i=1; i<=n; i++){
			for(int j=1; j<=n;j++){
				R[k][i][j] = R[k-1][i][j] | (R[k-1][i][k] & R[k-1][k][j]) ;
				opCount++;
			}
		}
	}
}

