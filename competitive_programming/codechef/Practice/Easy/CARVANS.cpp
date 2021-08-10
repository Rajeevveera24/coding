#include <iostream>
using namespace std;

int main() {
	int t, n, m, speed, count;
	
	scanf("%d", &t);
	
	while(t--){
	    scanf("%d", &n);
	    
	    m = 2147483647;
	    count = 0;
	    
	    for(int i=0; i<n; i++){
	        scanf("%d", &speed);
	       // printf("Here\n");
	       // printf("%d %d\n", m, speed);
	        if(speed <= m){
	            count++;
	            m = speed;
	        }
	    }
	    
	    printf("%d\n", count);
	}
	return 0;
}
