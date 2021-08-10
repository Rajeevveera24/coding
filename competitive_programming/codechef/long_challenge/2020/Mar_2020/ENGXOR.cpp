#include <iostream>
using namespace std;

bool isEven(int x)
{
    x ^= x>>16;
    x ^= x>>8;
    x ^= x>>4;
    x ^= x>>2;
    x ^= x>>1;

    return !(x & 1);
}

int main() {
	int t, p, n, q, a[100000], evenCount, oddCount;
	cin >> t;
	while(t--){
	    
	    scanf("%d %d",&n, &q);
	    
	   // a = (int*)malloc(sizeof(int) * n);
	   
	    evenCount = 0;
	    for(int i=0; i<n; i++){
	        scanf("%d", &a[i]);
	        if(isEven(a[i])){
	            evenCount++;
	        }
	    }
	    oddCount = n - evenCount;
	    
	    for(int i=0; i<q; i++){
	        scanf("%d", &p);
	        if(isEven(p)){
	            printf("%d %d\n", evenCount, oddCount);
	        }
	        else{
	            printf("%d %d\n", oddCount, evenCount);
	        }
	    }
	    
	   // free(a);
	}
	return 0;
}
