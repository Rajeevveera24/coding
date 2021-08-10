#include <iostream>
using namespace std;

int c(int n){
    if(n<2){
        return 0;
    }
    if(n==2){
        return 1;
    }
    return ((n*(n-1))/2);
}

int main() {
	int t, n, a, count, n0, n2;
	cin>>t;
	while(t--){
	    count = 0;
	    cin>>n;
	    n0 = n2 = 0;
	    for(int i=0; i<n; i++){
	        cin>>a;
	        if(a == 0){
	            n0++;
	        }
	        else if(a==2){
	            n2++;
	        }
	    }
	    count = c(n2) + c(n0);
	    
	   // for(int i=0; i<n-1; i++){
	   //     for(int j=i+1; j<n; j++){
	   //         if((a[i]*a[j]) == (a[i] + a[j])){
	   //             count++;
	   //         }
	   //     }
	   // }
	    cout<<count<<endl;
	}
	return 0;
}