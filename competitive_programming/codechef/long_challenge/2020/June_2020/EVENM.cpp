#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
	
	int t, n, count, cnt;
	
	scanf("%d", &t);
	
	while(t--){
	    
	    scanf("%d", &n);
        
        count = 1;
        
        if(n % 2 == 0){
            
            for(int i=0; i<n; i++){
                cnt = n;
                for(int j=0; j<n; j++){
                    if(i%2 == 0){
                        printf("%d ", count);
                        count++;
                    }
                    else{
                        printf("%d ", i*n + cnt);
                        count++;
                        cnt--;
                    }
                }
                printf("\n");
            }
        }
        else{
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    printf("%d ", count);
                    count++;
                }
                printf("\n");
            }
        }
	}
	return 0;
}
