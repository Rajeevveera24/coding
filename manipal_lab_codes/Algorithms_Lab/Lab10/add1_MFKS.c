#include <stdio.h>

#define MAXI 100

int max(int a, int b){
	return a>b?a:b;
}

int v[MAXI][MAXI], val[5] = {0,12,10,20,15}, w[5] = {0,2,1,3,2}, wt=5;  

int MFKS(int i, int j){
	int  value = 0;
	if(v[i][j] < 0){
		if(j < w[i]){
			//printf("Here\n");
			value = MFKS(i-1, j);
		}
		else{
			//printf("Here\n");
			value = max(MFKS(i-1,j), val[i] + MFKS(i-1, j-w[i]));
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
	int size;
	// scanf("%d", &size);
	size = 4;
	// w = {2,1,3,2};
	// val = {12,10,20,15};
	wt = 5;
	// for(int i=1; i<=size; i++){
	// 	scanf("%d %d", &w[i], &val[i]);
	// }
	// scanf("%d", &wt);
	for(int i=0; i<=size; i++){
		for(int j=0; j<=wt; j++){
			v[i][j] = 0;
		}
	}
	for(int i=1; i<=size; i++){
		for(int j=1; j<=wt; j++){
			v[i][j] = -1;
		}
	}
	int ans = MFKS(4, 5);
	for(int i=0; i<=size; i++){
		for(int j=0; j<=wt; j++){
			printf("%d ", v[i][j]);
		}
		printf("\n");
	}
	printf("%d\n", ans);
	return 0;
}