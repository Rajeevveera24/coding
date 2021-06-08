//done
import java.util.Scanner;

class lab1ex4{
	public static void main(String args[]){
		Scanner sc=new Scanner(System.in);
		int num=2,count=1;
		System.out.println("Enter the value of n");
		int n = sc.nextInt();
		System.out.println("The first "+n+" prime numbers are:");
		
		while(count<=n)
		{
			if(Prime(num)==1)
			{
				count+=1;
				System.out.println(num);
			}
			num+=1;
		}
	
	}

	public static int Prime(int num){
		int count=2,flag=1;
		while(count <= num/2)
		{
			if(num%count==0)
			{	flag=0;
				break;	
			}
			else
				count+=1;
		}
		return flag;
	}
}
