// stdio.h, string.h have been included for this problem.
// You don't need any other header files.

// Add any helper functions(if needed) above.
int min_weight_path(int row, int col, int grid[row][col]){
    int path[row][col];
    
    path[row-1][col-1] = grid[row-1][col-1];
    
    for(int i=row-2; i>=0; i--){
        path[i][col-1] = grid[i][col-1] + path[i+1][col-1];
    }
    for(int i=col-2; i>=0; i--){
        path[row-1][i] = grid[row-1][i] + path[row-1][i+1];
    }
    
    for(int i=row-2; i >= 0; i--){
        for(int j=col-2; j >= 0; j--){
            path[i][j] = grid[i][j];
            path[i][j] += ((path[i+1][j] < path[i][j+1]) ? (path[i+1][j]):(path[i][j+1]));
        }
    }
    return path[0][0];
}