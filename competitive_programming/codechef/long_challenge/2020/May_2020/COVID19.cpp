#include <iostream>
using namespace std;


int checkRight(int x[], int i, int n){
    if(i == n-1){
        return 0;
    }
    if((x[i+1] - x[i]) <= 2){
        return ( 1 + checkRight(x, i+1, n));
    }
    return 0;
}

int checkLeft(int x[], int i, int n){
    if(i==0){
        return 0;
    }
    if((x[i] - x[i-1]) <= 2){
        return ( 1 + checkLeft(x, i-1, n));
    }
    return 0;
}

int main() {
	int t,n,x[8], min, max, num;
	scanf("%d", &t);
	while(t--){
	    scanf("%d", &n);
	    max = 1;
	    min = n;
	    num = 0;
	    for(int i=0; i<n; i++){
	        scanf("%d", &x[i]);
	    }
	    for(int i=0; i<n; i++){
	        num = 1 + checkLeft(x, i, n) + checkRight(x, i, n);
	        max = ((max > num) ? max : num);
	        min = ((min < num) ? min : num);
	    }
	    printf("%d %d\n", min, max);
	}
	return 0;
}
