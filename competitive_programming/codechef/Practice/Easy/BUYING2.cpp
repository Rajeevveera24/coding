#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

int main() {
	int t, n, x, a[100], sum, k;
	scanf("%d", &t);
	while(t--){
	    
	    scanf("%d %d", &n, &x);
	    
	    sum = 0;
	    
	    memset(a, 0, sizeof(a));
	    
	    for(int i=0; i<n; i++){
	        scanf("%d", &a[i]);
	        sum += a[i];
	    }
	    
	    sort(a, a+n);
	    
	    k = sum / x;
	    
	    if(sum % x == 0){
	        printf("%d\n", k);
	    }
	    else{
	        if((sum % x) >= a[0]){
	            printf("%d\n",-1);
	        }
	        else{
	            printf("%d\n", k);
	        }
	    }
	}
	return 0;
}
