#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int t,n,x[800000], y[800000], count1, x1, y1, prev;
	
	scanf("%d", &t);
	while(t--){
	    scanf("%d", &n);
	    for(int i=0; i < 4*n -1; i++){
	        scanf("%d %d", &x[i], &y[i]);
	    }
	    
	    sort(x, x+4*n-1);
	    sort(y, y+4*n-1);
	    
	    count1 = 1;
	    prev = x[0];
	    
	    for(int i=1; i<4*n-1; i++){
	        if(x[i] == prev){
	            count1++;
            }
            else{
                if(count1 % 2 == 0){
                    count1 = 1;
                    prev = x[i];
                }
                else{
                    // prev = x[i];
                    break;
                }
            }
        }
        x1 = prev;
        
        count1 = 1;
	    prev = y[0];
	    
        for(int i=1; i<4*n-1; i++){
	        if(y[i] == prev){
	            count1++;
            }
            else{
                if(count1 % 2 == 0){
                    count1 = 1;
                    prev = y[i];
                }
                else{
                    // prev = y[i];
                    break;
                }
            }
        }
        y1 = prev;
        
        printf("%d %d\n", x1, y1);
        
	}
	return 0;
}
