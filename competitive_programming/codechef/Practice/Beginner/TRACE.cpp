#include <iostream>
using namespace std;

int main() {
	int t, n, mat[100][100], sum, max;
	cin>>t;
	while(t--){
	    cin>>n;
	    for(int i=0; i<n; i++){
	        for(int j=0; j<n; j++){
	            cin>>mat[i][j];
	        }
	    }
	    sum = max = 0;
	    for(int i=0, j=0; i<n && j<n; i++, j++){
	    	sum += mat[i][j];
	    }
	    max = sum;
	    for(int k=1; k<n; k++){
	    	sum = 0;
	    	for(int i=0, j = k; j<n; i++, j++){
	    		sum += mat[i][j]; 
	    	}
	    	max = sum > max ? sum : max ; 
	    }
	    for(int k=1; k<n; k++){
	    	sum = 0;
	    	for(int i=k, j=0; i<n; i++, j++){
	    		sum += mat[i][j]; 
	    	}
	    	max = sum > max ? sum : max ; 
	    }
	    cout<<max<<endl;
	}
	return 0;
}
