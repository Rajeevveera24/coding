#include <stdio.h> 

int val[20], wt[20], W = 50, n;

int max(int a, int b){
    return (a > b)? a : b;
} 
 
int knapSack(int W, int wt[], int val[], int n){ 
    
   if (n == 0 || W == 0){ 
       return 0; 
   }
   if (wt[n-1] > W){
       return knapSack(W, wt, val, n-1); 
   }
   else{
        return max( val[n-1] + knapSack(W-wt[n-1], wt, val, n-1), knapSack(W, wt, val, n-1)); 
   }
} 
 
int main(){ 

    printf("Enter the number of items(20 or lesser): ");
    scanf("%d", &n);
    printf("Enter the values of the items: ");
    for(int i=0; i<n; i++){
        scanf("%d", &val[i]);
    }
    printf("Enter the weights of the items:");
    for(int i=0; i<n; i++){
        scanf("%d", &wt[i]);
    }
    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &W);

    printf("Maximum value is %d\n", knapSack(W, wt, val, n)); 
    return 0; 
} 
