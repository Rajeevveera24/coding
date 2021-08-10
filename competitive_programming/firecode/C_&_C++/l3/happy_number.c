// stdio.h, string.h have been included for this problem.
// You don't need any other header files.

int is_happy_number(int input) {
    if(input <= 0){
        return 0;
    }
    if(input == 1){
        return 1;
    }
    if(input <= 9){
        return 0;
    }
    int copy = input, digit_sum;
    while(copy >= 10){
        digit_sum = 0;
        while(copy>0){
            digit_sum += (copy%10)*(copy%10);
            copy /= 10;
        }
        if(digit_sum == 1){
            return 1;
        }
        copy = digit_sum;
    }
    return 0;
}