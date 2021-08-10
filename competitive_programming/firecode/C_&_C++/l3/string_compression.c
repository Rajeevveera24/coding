// stdio.h, string.h have been included for this problem.
// You don't need any other header files.

// Add any helper functions(if needed) above.
char* compress_string(char*  text) {
    char* result = (char*) malloc(sizeof(char*)*strlen(text)+1);  
    // Add your code below this line. Do not modify any other code. 
    if(!text){
        return NULL;
    }
    int len = strlen(text);
    if(len == 0){
        return result;
    }
    char prev = text[0];
    int count = 1;
    int count1 = 0;
    // result[0] = prev;
    for(int i=1; i<len; i++){
        if(prev == text[i]){
            count++;
        }
        else{
            if(count > 1){
                result[count1++] = prev;
                result[count1++] = (char)(count + 48);
            }
            else{
                result[count1++] = prev;
            }
            prev = text[i];
            count = 1;
        }
    }
    if(count > 1){
        result[count1++] = prev;
        result[count1++] = (char)(count + 48);
    }
    else{
        result[count1++] = prev; 
    }
    // Add your code above this line. Do not modify any other code.
    return result;
}