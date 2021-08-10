//Check if 2 strings are permutations of each other...

// stdio.h, string.h have been included for this problem.
// You don't need any other header files.

// Add any helper functions(if needed) above.
int premutation (char* str1, char* str2) {
    int l1 = strlen(str1), l2 = strlen(str2);
    if(l1 != l2){
        return 0;
    }
    int l[256];
    for(int i=0; i<256; i++){
        l[i] = 0;
    }
    for(int i=0; i<l1; i++){
        l[(int)(str1[i])]++;
    }
    for(int i=0; i<l2; i++){
        if((--l[(int)(str2[i])]) < 0){
            return 0;
        }
    }
    for(int i=0; i<256; i++){
        if(l[i] != 0){
            return 0;
        }
    }
    return 1;
}