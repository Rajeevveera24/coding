#include <string.h>
#include <iostream>
using namespace std;

int main() {
	int t, sum;
	string s;
	cin>>t;
	while(t--){
	    cin>>s;
	    sum = 0;
	    for(int i=0; i<s.length(); i++){
	        if(isdigit(s[i])){
	            sum += s[i] - 48;
	        }
	    }
	    cout<<sum<<endl;
	}
	return 0;
}
