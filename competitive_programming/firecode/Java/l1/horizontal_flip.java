// java.util.* and java.util.streams.* have been imported for this problem.
// You don't need any other imports.

public static void flipHorizontalAxis(int[][] matrix) {
    int rows = matrix.length, cols = matrix[0].length;
    int tmp;
    for(int r = 0; r < rows/2; r++){
        for(int c=0; c < cols; c++){
            tmp = matrix[r][c];
            matrix[r][c] = matrix[rows-r-1][c];
            matrix[rows-r-1][c] = tmp;
        }
    }
}