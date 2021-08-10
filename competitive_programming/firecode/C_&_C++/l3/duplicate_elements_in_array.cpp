#include <algorithm>
// namespace std have been included for this problem.

// Add any helper functions(if needed) above.
int* remove_dup(int A[], int sz)
{    /* Alocate the memory of Output array of maximum size n. 
    Fill the new array with unique elements, which have duplicates entries in input array 
    Size of Output array will be less than n. */
    int *output = NULL;
    // Add your code below this line. Do not modify any other code.
    if(sz <= 1){
        return output;
    }
    output = new int[sz];
    std::sort(A, A+sz);
    
    int cnt1 = 0, count = 0;
    
    for(int i=1; i<sz; i++){
        if(A[i] == A[i-1]){
            count++;
            if(count == 1){
                output[cnt1++] = A[i];
            }
        }
        else{
            count = 0;
        }
    }
    
    // Add your code above this line. Do not modify any other code.
    return output;
    
}
