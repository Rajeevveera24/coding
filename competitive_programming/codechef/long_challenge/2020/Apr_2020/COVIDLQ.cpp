#include <iostream>
using namespace std;

int main() {
	int t, n, prev_pos, pos, num, flag;
	scanf("%d", &t);
	while(t--){
	    
	    scanf("%d", &n);
	    
	    prev_pos = -6;
	    pos = 0;
	    flag = 0;
	    
	    for(int i=0; i<n; i++){
	        scanf("%d", &num);
	        if(num == 1){
	            if((pos - prev_pos) < 6){
	                flag = 1;
	               // break;
	            }
	            else{
	                prev_pos = pos;
	            }
	        }
	        pos++;
	    }
	    
	    if(flag){
	        printf("NO\n");
	    }
	    else{
	        printf("YES\n");
	    }
	}
	return 0;
}
