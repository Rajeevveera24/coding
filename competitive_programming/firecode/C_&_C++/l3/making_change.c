// Given an array containing the available denominations of coins in descending order, write a function to compute the number of possible ways of representing a monetary amount in cents.

// For simplicity, assume that there are an infinite number of coins available for each coin denomination in the array.


// stdio.h, string.h have been included for this problem.
// You don't need any other header files.
// stdio.h, string.h have been included for this problem.
// You don't need any other header files.

int count (int coins[], int size, int idx, int amount){
    if(amount == 0){
        return 1;
    }
    if(idx == size){
        return 0;
    }
    int ret = 0;
    for(int i=0; i*coins[idx] <= amount; i++){
        ret += count(coins, size, idx+1, amount - i*coins[idx]);
    }
    return ret;
}
// Add any helper functions(if needed) above.
int make_change(int coins[], int n, int amount){    
    return count(coins, n, 0, amount);
}