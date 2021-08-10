// Write a function that recursively checks if a given integer is a palindrome or not. If the number is a palindrome, return 1, else return 0.


// stdio.h, string.h have been included for this problem.
// You don't need any other header files.
int rec_pal(int num, int *num1){
    if(num >= 0 && num <= 9){
        return (num == *num1 % 10);
    }
    if(!rec_pal(num/10, num1)){
        return 0;
    }
    (*num1) = (*num1) / 10;
    return num%10 == (*num1%10);
    
}
// Add any helper functions(if needed) above.
int is_palindrome(int num){            
    int num1 = num;
    return rec_pal(num, &num1);
}