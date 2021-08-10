// Given an array consisting of both positive and negative integers, find the maximum sum among 
// all the contiguous subsequences of the input array. 
// Write a function that takes in an array of integers arr with the size sz and returns the maximum sum. 
// For an empty array, return 0. The maximum and minmimum possible numbers in the array can be 999 and -999



// stdio.h, string.h have been included for this problem.
// You don't need any other header files.
// int max_cont_sum(int a[], int s, int e){
    
//     if(s>e){
//         return -999;
//     }
//     if(s == e){
//         return a[s];
//     }
    
//     int m = (s+e)/2;
//     int right = max_cont_sum(a, m+1, e);
//     int left = max_cont_sum(a, s, m);
//     int sum = 0, max_left = a[m], max_right = a[m+1];
    
//     for(int i=m; i>=s; i--){
//         sum += a[i];
//         if(sum > max_left){
//             max_left = sum;
//         }
//     }
    
//     sum = 0;
//     for(int i=m+1; i<=e; i++){
//         sum += a[i];
//         if(sum > max_right){
//             max_right = sum;
//         }
//     }
    
//     sum = max_left + max_right;
    
//     if(sum > left && sum > right){
//         return sum;
//     }
//     return (left>right)?(left):(right);
// }
// Add any helper functions(if needed) above.
int max_sum_cont_sequence(int arr[], int sz){
    if(sz == 0){
        return 0;
    }
    // return max_cont_sum(arr, 0, sz-1);
    int sum = arr[0], max = (sum > -999)?sum:-999;

    for(int i=1; i<sz; i++){
        if(sum > 0){
            sum += arr[i];
        }
        else{
            sum = arr[i];
        }
        if(max < sum){
            max = sum;
        }
    }
    
    // int max = -999;
    // for(int i=sz-1; i>=0; i--){
    //     if(max < arr[i]){
    //         max = arr[i];
    //     }
    // }
    return max;
}