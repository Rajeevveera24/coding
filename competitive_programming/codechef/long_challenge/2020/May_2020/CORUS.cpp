#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void printTable(int arr[]){
    for(int i=0; i<26; i++){
        printf("%c:\t%d\n", i+97, arr[i]);
    }    
}

int main() {
	
	int t, n, q, c, arr[26], waiting;
	
	string str;
	
	scanf("%d", &t);
	
	while(t--){
	        
	    scanf("%d %d", &n, &q);
	    
	    cin >> str;
	    
	    memset(arr, 0, sizeof(arr));
	    
        for(int i=0; i<n; i++){
            arr[(int)((int)(str[i]) - 97)]++;
        }
	    
	   // printTable(arr);
	    
	    for(int i=0; i<q; i++){
	        scanf("%d", &c);
	        waiting = 0;
	        for(int j=0; j<26; j++){
	            if(arr[j] > c){
	                waiting += (arr[j] - c);
	            }
	        }
	        cout << waiting << endl;
	    }
	}
	
	return 0;
}
