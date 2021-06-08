import java.util.Scanner;
class NewThread1 extends Thread{
	int col[] = new int [10];
	int size,sum;
	NewThread1(int  []col, int size){
		super("Column Thread");
		this.size = size;
		for(int i=0;i<size;i++){
			this.col[i] = col[i];
		}
		sum=0;
		start();
	}
	public void run(){
			for(int i:col){
				sum+=i;
			}
		System.out.println("Exiting Row");
	}
	int getSum(){
		return sum;
	}
}
class Matrix{
	public static void main(String[] args) throws InterruptedException {
		Scanner scan = new Scanner(System.in);
		System.out.println("Enter the row and column sizes of the matrix");
		int row = scan.nextInt();
		int col = scan.nextInt();
		int mat[][] = new int[row][col];
		int sum[] = new int[row];
		int sum1=0;
		System.out.println("Enter the elements");
		for(int i=0;i<row;i++){
			for(int j=0;j<col;j++){
				mat[i][j] = scan.nextInt();
			}
			NewThread1 t = new NewThread1(mat[i],col);
			t.join();
			sum[i] = t.getSum();
		}
		for(int i=0;i<row;i++){
			System.out.println(sum[i]);
			sum1+=sum[i];
		}
		System.out.println(sum1);
	}
}
