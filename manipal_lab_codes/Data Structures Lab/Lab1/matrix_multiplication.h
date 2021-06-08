void Matprod(int mat1[][10], int mat2[][10], int mat3[][10], int row1, int col1, int col2)
{
	int i,j,k;
	for(i=0;i<row1;i++)
	{
		for(j=0;j<col2;j++)
		{
			mat3[i][j]=0;
			for(k=0;k<col1;k++)
			{
				mat3[i][j] += mat1[i][k]*mat2[k][j];
			}
		}
	}
}

void Matinput(int mat[][10],int row, int col)
{
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<col;j++)
		{
			scanf("%d",&mat[i][j]);
		}
	}
}

void Matoutput(int mat[][10], int row, int col)
{
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<col;j++)
		{
			printf("%d",mat[i][j]);
			printf("\t");
		}
		printf("\n");
	}
}