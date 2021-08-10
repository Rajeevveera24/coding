#include <iostream>
#include <math.h>

using namespace std;

int main() {
	int t;
	unsigned long long ts, temp, js;
	int count;
	scanf("%d", &t);
	while(t--){
	    scanf("%lld", &ts);
	    temp = ts;
	    count = 0;
	    while(ts % 2 == 0){
	        ts /= 2;
	        count++;
	    }
	    if(ts % 2 == 1){
	        js = (ts - 1)/2;
	        printf("%lld\n", js );
	    }
	}
	return 0;
}
