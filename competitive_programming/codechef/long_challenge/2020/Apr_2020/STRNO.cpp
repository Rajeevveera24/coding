#include <iostream>
#include <math.h>
#include <bits/stdc++.h>
using namespace std;

bool isPrime(long n){ 
    // Corner cases 
    if (n <= 1)  return false; 
    if (n <= 3)  return true; 
  
    if (n%2 == 0 || n%3 == 0) return false; 
  
    for (long i=5; i*i<=n; i=i+6){
        if (n%i == 0 || n%(i+2) == 0){
            return false; 
        }
    }
    
    return true; 
} 

int getFactorization(int x, int k){ 
    int count = 0;
    // int prime = 2;
    
    while(x % 2 == 0){
        x /= 2;
        count++;
        if(count >= k){
            return 1;
        }
    }
    for(int i=3; i <= pow(x, 0.5); i += 2){
        while(x%i == 0){
            count++;
            x /= i;
            if(count >= k){
                return 1;
            }
        }
    }
    if(x > 2){
        count++;
    }
    if(count >= k){
        return 1;
    }

    return 0; 
} 

int main(){
	
	int t, k;
	int x;
	
	scanf("%d", &t);

	while(t--){
	    
	    scanf("%d %d", &x, &k);
	    
	    if(k >= 30){
	        printf("0\n");
	    }
	    else if(x < pow(2, k)){
	        printf("0\n");
	    }
	    else if(k == 1){
	       printf("1\n");
	    }
	    else if(k == 2){
	        if(x % 2 == 0){
	            printf("1\n");
	        }
	        else if(!isPrime(x)){
	            printf("1\n");
	        }
	        else{
	            printf("0\n");
	        }
	    }
	    else{
            if(isPrime(x)){
                printf("0\n");
            }
	        else if(getFactorization(x,k)){
	            printf("1\n");
	        }
	        else{
	            printf("0\n");
	        }
	    }
	}
	return 0;
}
