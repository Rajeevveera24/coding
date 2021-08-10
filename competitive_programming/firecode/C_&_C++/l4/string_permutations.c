// Write a recursive function - get_permutations that finds all permutations of the input string char *str 
// and adds the results to the resultant set by calling the void addstring(char*) function. 
// Define helper functions if needed. For simplicity, you should assume that all characters in the string are unique.

// stdio.h, string.h have been included for this problem.
// You don't need any other header files.
void swap(char *x, char *y){
    int tmp = *x;
    *x = *y;
    *y = tmp;
}
void permute(char *str, int index, int len){
    if(index == len){
        addstring(str);
    }
    else{
        for(int j=index; j<=len; j++){
            swap(&str[index], &str[j]);
            permute(str, index+1, len);
            swap(&str[j], &str[index]);
        }
    }
}
// Add any helper functions(if needed) above.
// Call void addstring(char *resultstr) function to add each of the output string in the resultant set
void get_permutations(char* str){
    permute(str, 0, strlen(str)-1);
}