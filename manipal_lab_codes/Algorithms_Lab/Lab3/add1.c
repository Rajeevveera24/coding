#include <stdio.h>
#include <stdlib.h>

int **createMatrix(int row, int col);
int **multiplyMatrix(int ** a, int** b, int row_a, int col_a, int row_b, int col_b);
void displayMatrix(int **mat, int row, int col);

int main(){

	int **mat1, **mat2, **mat3, row1, col1, row2, col2;

	printf("\nPlease enter the row and column size of the first matrix:\t");
	scanf("%d %d",&row1, &col1);

	printf("Creating the first matrix with %d rows and %d columns...\n\n", row1, col1);
	mat1 = createMatrix(row1,col1);
	displayMatrix(mat1,row1,col1);

	printf("\nPlease enter the row and column size of the second matrix:\t");
	scanf("%d %d",&row2, &col2);
	printf("Creating the second matrix with %d rows and %d columns...\n\n", row2, col2);
	mat2 = createMatrix(row2,col2);
	displayMatrix(mat2,row2,col2);

	mat3 = multiplyMatrix(mat1, mat2, row1, col1, row2, col2);
	displayMatrix(mat3,row1,col2);

	return 0;
}

void displayMatrix(int **mat, int row, int col){

	if(mat == NULL){
		return;
	}

	printf("Elements of the matrix are...\n");

	for(int i=0;i<row; i++){
		for(int j=0;j<col;j++){
			printf("%d ",mat[i][j]);
		}
		printf("\n");
	}
}

int **multiplyMatrix(int ** a, int** b, int row_a, int col_a, int row_b, int col_b){

	if(col_a != row_b){
		printf("Given matrices are incompatible for mulitplication...\n\n");
		return NULL;
	}

	printf("\nMultiplying the matrices...\n\n");

	int** mat = (int**)malloc(sizeof(int*) * row_a);
	int sum;

	for(int i=0;i<row_a;i++){

		mat[i] = (int*)malloc(sizeof(int)*col_b);

		for(int j=0;j<col_b;j++){
			
			sum = 0;

			for(int k=0;k<col_a;k++){
				sum += a[i][k] * b[k][j];
			}

			mat[i][j] = sum;
		}
	}

	return mat;
}

int **createMatrix(int row, int col){

	int** mat = (int**)malloc(sizeof(int*) * row);

	printf("Please enter the elements of the matrix row wise:\t");

	for(int i=0;i<row;i++){

		mat[i] = (int*)malloc(sizeof(int)*col);

		for(int j=0; j<col;j++){
			scanf("%d",&mat[i][j]);
		}
	}

	printf("\nThank you. The matrix has been successfully created with the given values...\n\n");

	return mat;
}