import java.util.Scanner;

class Lab2ex4
{
	public static void main(String[] args)
	{
		int row,col,i,j;
		
		Scanner scan = new Scanner(System.in);
		
		System.out.println("Enter the row and column sizes of the matrices");
		row = scan.nextInt();
		col = scan.nextInt();
		
		int [][] mat1 = new int[row][col];
		int [][] mat2 = new int[row][col];
		int [][] mat3 = new int[row][col];
		
		System.out.println("Enter the elements of the first matrix");
		matin(mat1,row,col);
		
		System.out.println("Enter the elements of the second matrix");
		matin(mat2,row,col);
		
		System.out.println("Elements of the first matrix are");
		matout(mat1,row,col);
		
		System.out.println("Elements of the second matrix are");
		matout(mat2,row,col);
		
		for(i=0;i<row;i++)
			for(j=0;j<col;j++)
				mat3[i][j] = mat1[i][j]+mat2[i][j];
		
		System.out.println("Resultant Matrix is");
		matout(mat3,row,col);
	}
	
	public static void matin(int mat[][], int row, int col)
	{
		int i,j;
		
		Scanner scan = new Scanner(System.in);
		
		for(i=0;i<row;i++)
			for(j=0;j<col;j++)
				mat[i][j]=scan.nextInt();
	}
	
	public static void matout(int mat[][], int row, int col)
	{
		int i,j;
		
		for(i=0;i<row;i++)
		{
			for(j=0;j<col;j++)
				System.out.print(mat[i][j]+"\t");
			
			System.out.println();
		}
				
	}
}
	
				
