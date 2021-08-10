#include <iostream>
using namespace std;

int main() {
	int t, n;
	long int k, a, sum;
	cin >> t;
	while(t--){
	    cin >> n >> k;
	    sum = 0;
	    for(int i=0; i<n; i++){
	        cin >> a;
	        sum += a%k;
	    }
	    cout << sum % k << endl;
	}
	return 0;
}
