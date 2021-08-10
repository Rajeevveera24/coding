#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// const int N = 1000000;
// bool prime[ N + 1];

// bool p1[ N + 1 ];

// void SieveOfEratosthenes() {  

//     memset(prime, true, sizeof(prime));

//     for (int p = 2; p*p <= N; p++){ 
//         if (prime[p] == true){  
//             for (int i = p*p; i <= N; i += p){
//                 prime[i] = false; 
//             }
//         } 
//     }
// }

// void numPrimes(int n){    
    
//     int count = 0; 
    
//     for(int p=2; p <= n; p++){
//         if (prime[p]){ 
//             p1[p] = true;
//             count++;
//         } 
//     }
//     // printf("%d %d", count + 1, 1);
//     p1[1] = true;

//     for(int p=2; p <= n; p++){
//         if (prime[p]){ 
//             // printf(" %d", p);
//         }
//     }
//     // printf("\n");
// }

int gcd(int a, int b){
    while(a>0 && b>0){
        if(a >= b){
            a %= b;
        }
        else{
            b %= a;
        }
    }
    
    return ((a>b) ? a:b);
}

// int check(int x, int n){
//     int count = 1, num;
//     int i = x + 1;
//     while(i <= n){
//         if(!p1[i]){
//             if(gcd(x, i) == 1){
//                 num = i;
//                 p1[i] = true;
//                 p1[x] = true;
//                 // printf("2 %d %d\n", x, num);
//                 return 0;
//             }
//         }
//         i += 2;
//     }
//     // printf("1 %d\n", x);
//     p1[x] = true;
//     return 1;
// }

int main() {
    
	int t, n, d, y;
	scanf("%d", &t);
	
// 	SieveOfEratosthenes();
	
	while(t--){
	    
        scanf("%d", &n);
	   // memset(p1, false, n);
	    
	    if(n <= 3){
	        printf("1\n%d", n);
	        while(n > 0){
	            printf("% d", n--);
	        }
	        printf("\n");
	        continue;
	    }
	    
	    d = n / 2;
	    printf("%d\n", d);
	    
	   // numPrimes(n);
	   
	   if(n%2 == 1){
	       printf("3 1 2 3\n");
	       for(int x=4; x <= n-1; x += 2){
	           if(gcd(x, x+1) == 1){
	               printf("2 %d %d\n", x, x+1);
	           }
	           else{
	               printf("\n\n %d\t%d\n", x, x+1);
	               exit(0);
	           }
	       }
	   }
	   else{
	       printf("2 1 2\n");
	       for(int x = 3; x <= n-1; x += 2){
	           if(gcd(x, x+1) == 1){
	               printf("2 %d %d\n", x, x+1);
	           }
	           else{
	               printf("\n\n %d\t%d\n", x, x+1);
	               exit(0);
	           }
	       }
	   }
	}
	return 0;
}
