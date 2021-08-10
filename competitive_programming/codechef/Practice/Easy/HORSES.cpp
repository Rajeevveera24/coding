#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int main(){
	int t, n;
	long int s[5000], min;
	scanf("%d", &t);
	
	while(t--){
	    scanf("%d", &n);
	    memset(s, 0, sizeof(s));
	    for(int i=0; i<n; i++){
	        scanf("%d", &s[i]);
	    }
	    sort(s, s+n);
	    min = s[1] - s[0];
	    for( int i=1; i<n-1; i++){
	        if(s[i+1] - s[i] < min){
	            min  = s[i+1] - s[i];
	        }
	    }
	    printf("%d\n", min);
	}
	return 0;
}
