#include <stdio.h>
#define max 20

int v[max][max+1], val[max], wt[max], cap, size;

int maxi(int a, int b){
	return a>b?a:b;
}

int knapsack(int i, int j){
	int value = 0;
	if(v[i][j] < 0){
		if(wt[i] > j){
			value = knapsack(i-1, j);
		}
		else{
			value = maxi(knapsack(i-1, j), val[i] + knapsack(i-1, j-wt[i]));
		}
		v[i][j] = value;
	}
	else{
		value = v[i][j];
	}
	return value;
}

int main(int argc, char const *argv[])
{	
	scanf("%d", &size);
	val[0] = 0;
	for(int i=1 ;i<=size; i++){
		scanf("%d", &val[i]);
	}
	wt[0] = 0;
	for(int i=1; i<=size; i++){
		scanf("%d", &wt[i]);
	}
	scanf("%d", &cap);
	for(int i=0; i<=size; i++){
		for(int j=0; j<=cap; j++){
			v[i][j] = -1;
			if(j==0 || i == 0){
				v[i][j] = 0;
			}
		}
	}
	printf("%d\n", knapsack(size, cap));
	return 0;
}