// Implement a function that returns a number that appears only once in an array. 
// Assume that the array will surely have a unique value and that the rest of the 
// elements are repeated twice. The array will not be empty.

// stdio.h, string.h have been included for this problem.
// You don't need any other header files.

// Add any helper functions(if needed) above.
int single_number(int A[], int n) {            
    int num = 0;
    for(int i=0; i<n; i++){
        num ^= A[i];	//We can use this property since every other number is repeated only once (ie; appears twice in the array)
    }
    return num;
}