#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

int main() {
	
	int t, m, n, a[1000], b[1000], temp, cnt;
	
	cin >> t;
	
	while(t--){
	    
	    cin >> n >> m;
	    
	    memset(a, 0, sizeof(a));
	    memset(b, 0, sizeof(b));
	    
	   // if(m == n){
	   //     printf("\n\n");
	   //     continue;
	   // }
	    
	    for(int i=0; i<n; i++){
	        a[i] = i+1;
	    }
	    
	    for(int i=0; i<m; i++){
	        scanf("%d", &temp);
	        a[temp - 1] = 0;
	    }
	    
	    cnt = 0;
	    
	    for(int i=0; i<n; i++){
	        if(a[i] != 0){
	            b[cnt++] = a[i];
	        }
	    }
	    
	    sort(b, b + cnt);
	    
	    for(int i=0; i<cnt; i += 2){
	        cout << b[i] << " ";
	    }
	    cout <<  endl;
	    
	    for(int i=1; i<cnt; i += 2){
	        cout << b[i] << " ";
	    }
	    cout <<  endl;
	    
	}
	return 0;
}
