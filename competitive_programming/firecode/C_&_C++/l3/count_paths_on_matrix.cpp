// namespace std have been included for this problem.

// Add any helper functions(if needed) above.
int count_paths(int rows, int cols)
{
    int sol[rows][cols];
    
    for(int r = rows-1; r >= 0; r--){
        sol[r][cols-1] = 1;
    }
    for(int c = cols-1; c >= 0; c--){
        sol[rows-1][c] = 1;
    }
    
    for(int r = rows-2; r >= 0; r--){
        for(int c = cols-2; c>= 0; c--){
            sol[r][c] = sol[r][c+1] + sol[r+1][c];
        }
    }
    
    return sol[0][0]; 
}