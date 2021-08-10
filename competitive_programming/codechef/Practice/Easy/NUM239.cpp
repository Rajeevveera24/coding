#include <iostream>
using namespace std;

int main() {
	int t, l, r, count;
	cin>>t;
	while(t--){
	    cin>>l>>r;
	    count = 0;
	    for(int i=l; i<=r; i++){
	        int temp = i % 10;
	        if(temp == 2 || temp == 3 || temp == 9){
	            count++;
	        }
	    }
	    cout<<count<<endl;
	}
	return 0;
}