#include <stdio.h>
//#include <stdlib.h>

long c[10000][10000];

int min(int a, int b){
	if(a>b){
		return b;
	}
	else{
		return a;
	}
}

void binomial(int n, int k){
	for(int i=0; i<=n; i++){
		for(int j=0; j<=min(i,k); j++){
			if( i==0 || j==0){
				c[i][j] = 1;
			}
			else{
				c[i][j] = c[i-1][j-1] + c[i-1][j];
			}
		}
	}
}

int main(int argc, char const *argv[])
{
	int n,i,j,k;
	printf("Enter n and k: ");
	scanf("%d %d", &n ,&k);
	if(n<k){
		printf("Invalid input: n cannot be lesser than k\n");
		return 0;
	}
	else if(k<0){
		printf("Invalid input: k cannot be lesser than 0\n");
		return 0;
	}
	binomial(n,k);
	printf("Computed matrix is:\n");
	for(int i=0; i<=n; i++){
		for(int j=0; j<=min(i,k); j++){
			printf("%ld\t", c[i][j]);
		}
		printf("\n");
	}
	printf("binomial coefficient of c[%d][%d] is %ld\n", n, k, c[n][k]);
	return 0;
}