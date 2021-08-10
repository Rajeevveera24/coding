// stdio.h, string.h have been included for this problem.
// You don't need any other header files.

// Add any helper functions(if needed) above.
char first_non_repeating(char *str){
    int s[256], pos = strlen(str)-1;
    int prev = pos;
    
    for(int i=0; i<256; i++){
        s[i] = 0;
    }
    
    for(int i=strlen(str)-1; i>=0; i--){
        s[(int)str[i]]++;
    }
    
    for(int i=0; i<strlen(str); i++){
        if(s[(int)str[i]] == 1){
            return i;
        }
    }
    return -1;
}