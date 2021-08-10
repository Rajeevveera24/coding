#include <iostream>
// #include <stdio.h>
// #include <string>
using namespace std;

int main() {
	int t,n;
	cin >> t;
	while(t--){
	    cin >> n;
	    char s[n][10];
	    int w[10];
	    for(int i=0; i<10; i++){
	        w[i] = 0;
	    }
	    for(int i=0; i<n; i++){
	        scanf("%s", s[i]);
	        for(int j=0; j<10; j++){
	        	// cout << (int)s[i][j];
	            w[j] = w[j] ^ ((int)(s[i][j]) - 48); 
	        }
	    }
	    int count = 0;
	    for(int i=0; i<10; i++){
	        count += w[i];
	        // cout<<w[i];
	    }
	    cout << count << endl;
	}
	return 0;
}
