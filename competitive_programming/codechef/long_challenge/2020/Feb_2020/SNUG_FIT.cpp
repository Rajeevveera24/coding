#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int t, n;
	long int *a, *b, s;
	cin >> t;
	while(t--){
	    cin >> n;
	    a = (long int*)malloc(sizeof(long int) * n);
	    b = (long int*)malloc(sizeof(long int) * n);
	    
	    for(int i=0; i<n; i++){
	        cin >> a[i];
	    }
	    for(int i=0; i<n; i++){
	        cin >> b[i];
	    }
	    
	    sort(a, a + n);
	    sort(b, b + n);
	    
	    s = 0;
	    
	    for(int i=0; i<n; i++){
	        s += a[i] > b[i] ? b[i] : a[i];
	    }
	    cout << s << endl;
	    free(a);
	    free(b);
	}
	return 0;
}
