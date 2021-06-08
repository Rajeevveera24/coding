#include<stdio.h>
#include"matrix_multiplication.h"
int main()
{
	int mat1[10][10],mat2[10][10],mat3[10][10];
	int col1,row1,col2,row2,i,j;
	do
	{
		printf("Enter row and column size of first matrix\n");
		scanf("%d%d",&row1,&col1);
		printf("Enter row and column size of second matrix\n");
		scanf("%d%d",&row2,&col2);
		if(col1!=row2)
		{
			printf("Matrices can't be multiplied. Please enter the sizes again\n");
		}		
	}while(col1!=row2);

	printf("Enter Values of elements of first matrix\n");
	Matinput(mat1,row1,col1);
	printf("Enter Values of elements of second matrix\n");
	Matinput(mat2,row2,col2);		
	printf("Values of elements of first matrix:\n");
	Matoutput(mat1,row1,col1);
	printf("Values of elements of second matrix:\n");
	Matoutput(mat2,row2,col2);
	Matprod(mat1,mat2,mat3,row1,col1,col2); //function call for multiplication
	printf("Product of the two matrices is:\n");
	Matoutput(mat3,row1,col2);
	return 0;
}