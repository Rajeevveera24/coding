#include <iostream>
using namespace std;

int findFirst(int n){
    while(n/10 > 0){
        n/=10;
    }
    return n;
}
int main() {
	int t,n, last, first;
	cin>>t;
	while(t--){
	    cin>>n;
	    last = n%10;
	    first = findFirst(n);
	    cout << first + last<<endl;
	}
	return 0;
}
