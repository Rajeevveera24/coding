//done
import java.util.Scanner;

class lab1ex3{
	public static void main(String args[]){
		Scanner sc=new Scanner(System.in);
		System.out.println("Enter value of n and r respectively");
		int n = sc.nextInt();
		int r = sc.nextInt();
		int nCr = fact(n)/((fact(r))*(fact(n-r)));
		System.out.println(n+"C"+r+" is "+nCr);
	
	}

	public static int fact(int num){
		int factor=1;
		int count=2;
		while(num>=count)
			{
				factor*=count;
				count+=1;	
			}
		return factor;
		
	}
}
