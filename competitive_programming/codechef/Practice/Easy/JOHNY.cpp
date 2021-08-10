#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
	int t, k, n, a[100], count;
	scanf("%d", &t);
	while(t--){
	    scanf("%d", &n);
	    for(int i=0; i<n; i++){
	        scanf("%d", &a[i]);
	    }
	    
	    scanf("%d", &k);
	    count = 0;
	    for(int i=0; i<n; i++){
	        if(a[k-1] > a[i]){
	            count++;
	        }    
	    }
	    printf("%d\n", count+1);
	}
	return 0;
}
