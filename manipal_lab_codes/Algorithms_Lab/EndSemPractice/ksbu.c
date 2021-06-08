#include <stdio.h>
#define max 20

int val[max], wt[max], cap, size;

int maxi(int a, int b){
	return a>b?a:b;
}

int knapsack(int w, int n){
	if(n == 0 || w == 0){
		return 0;
	}
	if(wt[n-1] > w){
		return knapsack(w, n-1);
	}
	return maxi(val[n-1] + knapsack(w-wt[n-1], n-1), knapsack(w, n-1));
}

int main(int argc, char const *argv[])
{	
	scanf("%d", &size);
	for(int i=0 ;i<size; i++){
		scanf("%d", &val[i]);
	}
	for(int i=0; i<size; i++){
		scanf("%d", &wt[i]);
	}
	scanf("%d", &cap);
	printf("%d\n", knapsack(cap, size));
	return 0;
}