// Let's have some fun with 2D Matrices! 
// Write a function to traverse a 2D matrix of ints in a clockwise spiral order and 
// add the elements to an output output_arr.



// stdio.h, string.h have been included for this problem.
// You don't need any other header files.

// Add any helper functions(if needed) above.

int* find_spiral(int m, int n, int arr[m][n]){
    /* allocate ouput array of size equal to total number of elements in the input matrix */
    int* output_arr = (int *)calloc(m*n, sizeof(int));
    // Add your code above this line. Do not modify any other code.

    int count = 0, dir = 0, row = 0, col;
    
    int s0 = 0, e0 = n-1;
    int s1 = 1, e1 = m-1;
    int s2 = n-2, e2 = 0;
    int s3 = m-2, e3 = 1;
    // int cnt1 = 0;
    
    while(count <= m*n){
        // cnt1++;
        if(dir == 0){
            for(int i = s0; i<=e0; i++){
                output_arr[count++] = arr[row][i];
            }
            dir = 1;
            col = e0;
            s0 = s0 + 1;
            e0 = e0 - 1;
        }
        else if(dir == 1){
            for(int i=s1; i<= e1; i++){
                output_arr[count++] = arr[i][col];
            }
            dir = 2;
            row = e1;
            s1 = s1 + 1;
            e1 = e1 - 1;
        }
        else if(dir == 2){
            for(int i=s2; i >=  e2; i--){
                output_arr[count++] = arr[row][i];
            }
            dir = 3;
            col = e2;
            s2 = s2 - 1;
            e2 = e2 + 1;
        }
        else{
            for(int i=s3; i >=  e3; i--){
                output_arr[count++] = arr[i][col];
            }
            dir = 0;
            row = e3;
            s3 = s3 - 1;
            e3 = e3 + 1;
        }
        if(count == m*n){
        	break;
        }
    }

    // Add your code below this line. Do not modify any other code.
    return output_arr;
}