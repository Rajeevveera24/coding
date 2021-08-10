#include <iostream>
using namespace std;

int main() {
	int t, s, w[3], sum;
	cin>>t;
	while(t--){
	    sum = 0;
	   // count = 0;
	    cin>>s;
	    for(int i=0; i<3; i++){
	        cin>>w[i];
	        sum += w[i];
	    }
	    if(s >= sum){
	        cout<<1<<endl;
	       // continue;
	    }
	    else if(s >= (w[0] + w[1])){
	        cout<<2<<endl;
	    }
	    else{
	        if(s >= (w[1] + w[2])){
	            cout<<2<<endl;
	        }
	        else{
	            cout<<3<<endl;
	        }
	    }
	}
	return 0;
}
