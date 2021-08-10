// Write a function to determine if it is possible to choose a group of elements from a given array (with last index sz) 
// such that the sum of all numbers in the group is equal to a given target_sum.
// To make things more interesting, an additional constraint is also enforced : the group must include an 
// integer - must_have if it is present in the array. If there exists such a subset, return 1 else return 0


// stdio.h, string.h have been included for this problem.
// You don't need any other header files.
int subset_sum(int a[], int size, int num, int sum, int idx){
    if(sum == 0){
        return 1;
    }
    if(idx == size){
        return 0;
    }
    if(a[idx] == num){
        return subset_sum(a, size, num, sum-a[idx], idx+1);
    }
        return subset_sum(a, size, num, sum-a[idx], idx+1) || subset_sum(a, size, num, sum, idx+1);
}
// Add any helper functions(if needed) above.
int group_sum_with_num(int arr[], int sz, int must_have, int target_sum) {
    if(sz == 0){
        return 0;
    }
    return subset_sum(arr, sz, must_have, target_sum, 0);
}