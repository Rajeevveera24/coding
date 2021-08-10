#include <iostream>
using namespace std;

int main() {
	int t, g, q, n, i;
	cin >> t;
	while(t--){
	    scanf("%d", &g);
	    while(g--){
	        cin >> i >> n >> q;
	        if(n % 2 == 0){
	            cout << n/2 <<  endl;
	        }
	        else{
	            if(q == i){
	                cout << n/2 << endl;
	            }
	            else{
	                cout << n/2 + 1 << endl;
	            }
	        }
	    }
	}
	return 0;
}
