#include <iostream>
using namespace std;

int main() {
	int t;
	do{
	    cin>>t;
	    if(t == 42){
	        break;
	    }
	    cout<<t<<endl;
	}while(t != 42);
	return 0;
}
