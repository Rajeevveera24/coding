#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int t, s, n, a[100000], b[100000];
	scanf("%d %d", &t, &s);
	while(t--){
	    scanf("%d", &n);
	    for(int i=0; i<n; i++){
	        scanf("%d", &a[i]);
	    }
	    for(int i=0; i<n; i++){
	        scanf("%d", &b[i]);
	    }
	    
	    sort(a, a+n);
	    sort(b, b+n);
	    
	    int flag = 0;
	    
	    for(int i=0; i<n; i++){
	        if(a[i] >= b[i]){
	            flag = 1;
	            break;
	        }
	    }
	    
	    if(flag == 1){
	        printf("NO\n");
	        continue;
	    }
	    
	    int prevA = a[0];
	    int prevB = 0;
	    
	    int f = 0;
	    
	    for(int i=1; i<n; i++){
	        if(a[i] == a[i-1]){
	            continue;
	        }
	        else{
	            while(prevB < i){
	                if(a[i] == b[prevB]){
	                    break;
	                }
	                prevB++;
	            }
	            if(a[i] == b[prevB]){
	                continue;
	               // prevB++;
	            }
	            else{
	               // printf("Here: %d %d\n", a[i], b[prevB]);
	               // prevB++;
	                f = 1;
	                break;
	            }
	        }
	    }
	    if(f == 0){
	        printf("YES\n");
	    }
	    else{
	        printf("NO\n");
	    }
	}
	return 0;
}
