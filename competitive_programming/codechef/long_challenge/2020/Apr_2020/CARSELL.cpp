#include <iostream>
#include <algorithm>

using namespace std;

int price(int p, int x){
    if( (p-x) > 0){
        return (p-x);
    }
    else{
        return 0;
    }
}

int main() {
	int t, n, a[100000];
	long cost;
	scanf("%d", &t);
	
	while(t--){
	    scanf("%d", &n);
	    for(int i=0; i<n; i++){
	        scanf("%d", &a[i]);
	    }
	    
	    sort(a, a+n);
	    
	    cost = 0;
	    
	    for(int i = n-1; i >= 0; i--){
	        cost += price(a[i], n-1 - i);
	        cost %= 1000000007;
	    }
	    
	    printf("%d\n", cost);
	    
	}
	return 0;
}
