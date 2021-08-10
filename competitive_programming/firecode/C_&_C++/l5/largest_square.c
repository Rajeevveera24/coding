//In a matrix of 0s and 1s, find the area of the largest square submatrix of 1s


// stdio.h, string.h have been included for this problem.
// You don't need any other header files.
int min(int a, int b, int c){
    return (a<b?(a<c?a:c):(b<c?b:c));
}
// Add any helper functions(if needed) above.
int largest_square(int m, int n, int mat[m][n]){
   if(m == 0 || n == 0){
       return 0;
   }
   int sum[m][n];
   for(int i=m-1; i >= 0; i--){
       sum[i][n-1] = mat[i][n-1];
   }
   for(int i=n-1; i>=0; i--){
       sum[m-1][i] = mat[m-1][i];
   }
   
   for(int i=m-2; i >= 0; i--){
       for(int j=n-2; j >= 0; j--){
           sum[i][j] = (mat[i][j] == 0) ? (0) : (1 + min(sum[i+1][j], sum[i][j+1], sum[i+1][j+1]));
       }
   }
   
   int max = 0;
   
   for(int i=0; i<m; i++){
       for(int j=0; j<n; j++){
           if(sum[i][j] > max){
               max = sum[i][j];
           }
       }
   }
   return max*max;
}