import java.util.Scanner;

class Lab2add1
{
	public static void main(String[] args)
	{
		int i,size;
		
		System.out.println("Enter the size of the array");
		Scanner scan = new Scanner(System.in);
		size = scan.nextInt();
		
		int array[] = new int[size];
		
		System.out.println("Enter the elements of the array");
		for(i=0;i<size;i++)
		{
			array[i] = scan.nextInt();
		}
		
		System.out.println("Prime numbers in the array are");
		for(i=0;i<size;i++)
			prime(array[i]);	
		System.out.println();	
	}
	
	public static void prime(int num)
	{
		int i,flag=0;
		
		if(num==1)
			flag=1;
			 
		for(i=2;i<=num/2;i++)
			if(num%i==0)
			{
				flag=1;
				break;
			}
			
		if(flag==0)
			System.out.print(num+"\t");
	}
}
