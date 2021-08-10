// Write a function to compute the binary representation of a positive integer. 
// Return the representation as a number.


// stdio.h, string.h have been included for this problem.
// You don't need any other header files.

// Add any helper functions(if needed) above.
int compute_binary(int num){
    if(num == 0 || num == 1){
        return num;
    }
    return ((num%2) + 10 * compute_binary(num/2));
}