#include <iostream>
#include <bits/stdc++.h>
#include <string.h>
#include <stdio.h>

using namespace std;

int main() {
    
	int n, q, r[314159], c[314159], x, t, maxr, maxc;
	string s;
	
	scanf("%d %d", &n, &q);
	
	memset(r, 0, sizeof(r));
	memset(c, 0, sizeof(c));
	
	x = 5;
	
	for(int i=0; i < q; i++){
	    cin >> s;
	    cin >> t >> x;
	    if(s[0] == 'R'){
	        r[t-1] += x;
	    }
	    else{
	        c[t-1] += x;
	    }
	}
	
	maxc = 0;
	maxr = 0;
	
	for(int i=1; i<n; i++){
	    if(r[i] > r[maxr]){
	        maxr = i;
	    }
	    if(c[i] > c[maxc]){
	        maxc = i;   
	    }
	}
	
	printf("%d\n", r[maxr] + c[maxc]);
	
	return 0;
}
