// Write a function to determine if it is possible to choose a subset of elements from a given array 
// such that the sum of all numbers in the subset is equal to a given target. 
// If there exists such a subset, return 1, else return 0. Assume target is always a positive number.

// stdio.h, string.h have been included for this problem.
// You don't need any other header files.
int susbsetsum(int *arr, int index, int size, int target){
    if(target == 0){
        return 1;
    }
    if(index >= size){
        return 0;
    }
    return (susbsetsum(arr, index+1, size, target-arr[index]) || susbsetsum(arr, index+1, size, target));
}
// Add any helper functions(if needed) above.
int group_sum(int arr[], int sz, int target){
    return susbsetsum(arr, 0, sz, target);
}