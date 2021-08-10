// Given a string, write a function to list all the possible combinations of its characters. 
// Add each combination in the resultant set by calling void add_set(char*) function for each of them. 
// Don't add any duplicate combination in the results.



// stdio.h, string.h have been included for this problem.
// You don't need any other header files.
void find_combinations(char arr[], char data[], int s, int e, int idx, int r){
    if(r == idx){
        add_set(data);
    }
    else{
        for(int i=s; i <= e && e-i+1 >= r-idx; i++){
            data[idx] = arr[i];
            find_combinations(arr, data, i+1, e, idx+1, r);
        }
    }
}
// Add any helper functions(if needed) above.
void combinations(char arr[], int n) {
    char *data;
    for(int i=1; i<=n; i++){
        data = (char*)malloc(sizeof(char)*i);
        find_combinations(arr, data, 0, n-1, 0, i);
        free(data);
    }
}