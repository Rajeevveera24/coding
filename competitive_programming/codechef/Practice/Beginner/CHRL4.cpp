//Error - see python solution for the same problem...

#include <iostream>
using namespace std;


int main() {
	int n, k, j, min, b[100000];
	
	scanf("%d %d", &n, &k);
	
	long long int a[100000];
	
	for(int i=1; i<=n; i++){
	    scanf("%lld", &a[i]);
	}
	
	for( int i = n-1; i >= (n-k); i--){
	    a[i] = a[i] * a[n];
	}
	for(int i=(n-k)-1; i >= 1; i--){
	    j = 1;
	    min = i+1;
	    while(j <= k){
	        if(a[min] >= a[j + i]){
	            min = j + i;
	        }
	        j++;
	    }
	    a[i] = a[i] * a[min];  
	}
	
	printf("%lld\n", a[1] % 1000000007);
	return 0;
}
