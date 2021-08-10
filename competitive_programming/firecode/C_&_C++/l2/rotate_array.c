// stdio.h, string.h have been included for this problem.
// You don't need any other header files.

// Add any helper functions(if needed) above.
void rotate_left(int arraylist[], int sz, int k)
{
    k = k%sz;
    if(k == 0 || sz <= 1){
        return;
    }
    
    int tmp;
    
    for(int i=0; i<sz/2; i++){
        tmp = arraylist[i];
        arraylist[i] = arraylist[sz-1-i];
        arraylist[sz-1-i] = tmp;
    }
    
    for(int i=0; i<(sz-k)/2; i++){
        tmp = arraylist[i];
        arraylist[i] = arraylist[sz-k-1-i];
        arraylist[sz-k-1-i] = tmp;
    }
    for(int i=sz-k; i<(sz+(sz-k))/2; i++){
        tmp = arraylist[i];
        arraylist[i] = arraylist[sz-1-i + sz-k];
        arraylist[sz-1-i + sz-k] = tmp;
    }
}