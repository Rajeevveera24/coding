#include <iostream>
using namespace std;

int main() {
	long int t, D, d, P, Q, n, sumQ, ans;
	
	scanf("%ld", &t);
	while(t--){
	    scanf("%ld %ld %ld %ld", &D, &d, &P, &Q);
	    n = D/d - 1;
	    sumQ = (n*(n+1))/2;
	    ans = (P*D) + (sumQ*Q*d) + ((D%d)*(n+1)*Q);
	    printf("%ld\n", ans);
	}
	return 0;
}

