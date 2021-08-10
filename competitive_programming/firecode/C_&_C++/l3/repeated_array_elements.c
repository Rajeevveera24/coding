//Write a function to find the redundant or repeated elements in an array. 
//Save the set of redundant numbers in the given output array in ascending order. 
//Click Use Me to see the APIs and helper functions made available for this problem.


// stdio.h, string.h have been included for this problem.
// You don't need any other header files.

// Add any helper functions(if needed) above.
int* remove_dup(int A[], int n){
    int* output; 
    /* Alocate the memory of 'output' array of maximum size n. 
    Fill the new array with unique elements, which have duplicates entries in input array 
    Size of 'output' array will be less than n. */
    output = (int *)calloc(n,sizeof(int));  
    // Add your code below this line. Do not modify any other code.
    if( n <= 1){
        return NULL;
    }
    sort_arr(A, n);
    int cnt = 1, prev = A[0], out_cnt = 0;
    for(int i=1; i<n; i++){
        if(prev == A[i]){
            if(cnt == 1){
                output[out_cnt++] = prev;
            }
            cnt++;
        }
        else{
            prev = A[i];
            cnt = 1;
        }
    }
    if( cnt > 1){
        output[out_cnt++] = prev;
    }
    // Add your code above this line. Do not modify any other code.
    return output;
}