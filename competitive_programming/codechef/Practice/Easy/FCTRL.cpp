#include <iostream>
#include <math.h>
using namespace std;

int main() {
	int t;
	long int n, cnt;
	scanf("%d", &t);
	while(t--){
	    cnt = 0;
	    scanf("%ld", &n);
	    for(long int i = 1; pow(5,i) <= n; i++){
	        cnt = cnt +  (n / pow(5,i));
	    }
	    printf("%ld\n", cnt);
	}
	return 0;
}
