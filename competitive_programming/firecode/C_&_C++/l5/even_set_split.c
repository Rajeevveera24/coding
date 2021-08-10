 // Write a function to determine if it is possible to split an array of integers arr with its size sz 
 // into two parts such that the sum of all integers in each part is the same. An empty array cannot be split.


// stdio.h, string.h have been included for this problem.
// You don't need any other header files.
int subset_sum(int arr[], int index, int size, int sum){
    if(sum == 0){
        return 1;
    }
    if(index == size-1){
        return 0;
    }
    return subset_sum(arr, index+1, size, sum - arr[index]) || subset_sum(arr, index+1, size, sum);
}
// Add any helper functions(if needed) above.
int split_array(int arr[], int sz){
    if(sz == 0){
        return 0;
    }
    int sum = 0;
    for(int i=0; i<sz; i++){
        sum += arr[i];
    }
    if(sum%2 != 0){
        return 0;
    }
    return subset_sum(arr, 0, sz, sum/2);
}