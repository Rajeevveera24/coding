// stdio.h, string.h have been included for this problem.
// You don't need any other header files.

// Add any helper functions(if needed) above.
int is_isomorphic (char* input1, char* input2) {
    int len1 = strlen(input1), len2 = strlen(input2), idx1, idx2;
    
    if(len1 != len2){
        return 0;
    }
    
    int c1[256] = {0}, c2[256] = {0};
    
    for(int i=0; i<len1; i++){
        
        idx1 = (int)input1[i];
        if(c1[idx1] != 0){
            if(c1[idx1] != (int)input2[i]){
                return 0;
            }
        }
        else{
            c1[idx1] = (int)input2[i];
        }
        
        idx2 = (int)input2[i];
        if(c2[idx2] != 0){
            if(c2[idx2] != (int)input1[i]){
                return 0;
            }
        }
        else{
            c2[idx2] = (int)input1[i];
        }
        
    }
    return 1;
}