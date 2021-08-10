#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;
  

bool isSubsetSum(int set[], int n, int sum){ 
    if (sum == 0){
        return true;
    }
    
    if (n == 0 && sum != 0){
        return false; 
    }
  
    if (set[n - 1] > sum){
        return isSubsetSum(set, n - 1, sum); 
    }
    
    return (isSubsetSum(set, n - 1, sum) || isSubsetSum(set, n - 1, sum - set[n - 1])); 
} 
  
int main() 
{ 
    int t, n, m, a[20];
    scanf("%d", &t);
    while(t--){
        scanf("%d %d", &n, &m);
        memset(a, 0, sizeof(a));
        for(int i=0; i<n; i++){
            scanf("%d", &a[i]);
        }
        
        if(isSubsetSum(a, n, m)){
            printf("Yes\n");
        }
        else{
            printf("No\n");
        }
    }

    return 0; 
} 