// stdio.h, string.h have been included for this problem.
// You don't need any other header files.

void rotate_square_img_cw(int n, int matrix[n][n]){
    int tmp;
    for(int i=0; i<n/2; i++){
        for(int j=0; j<n; j++){
            tmp = matrix[n-1-i][j];
            matrix[n-1-i][j] = matrix[i][j];
            matrix[i][j] = tmp;
        }
    }
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            tmp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = tmp;
        }
    }
}