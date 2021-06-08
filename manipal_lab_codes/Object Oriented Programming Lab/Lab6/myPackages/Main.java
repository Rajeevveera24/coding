import p1.Max;
import java.util.Scanner;
class Main{
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		Max max = new Max();
		int a,b,c;
		int g[] = new int[3];
		float d,e,f;
		int large;
		float flarge;
		System.out.println("Enter 3 integers");
		a = scan.nextInt();
		g[0] = a;
		b = scan.nextInt();
		g[1] = b;
		c = scan.nextInt();
		g[2] = c;
		large = max.max(a,b,c);
		System.out.println("Lagest integer is "+large);
		large = max.max(g);
		System.out.println("Lagest integer using array is "+large);
		System.out.println("Enter 3 floating point numbers");
		d = scan.nextFloat();
		e = scan.nextFloat();
		f = scan.nextFloat();
		flarge = max.max(d,e,f);
		System.out.println("Largest floating point number is "+flarge);
		System.out.println("Enter the size of the matrix");
		int row = scan.nextInt();
		int col = scan.nextInt();
		int mat[][] = new int [row][col];
		System.out.println("Enter the elements of the matrix");
		for(int i=0;i<row;i++){
			for(int j=0;j<col;j++){
				mat[i][j] = scan.nextInt();
			}
		}
		large = max.max(mat);
		System.out.println("Largest element in the matrix is "+large);
	}
}