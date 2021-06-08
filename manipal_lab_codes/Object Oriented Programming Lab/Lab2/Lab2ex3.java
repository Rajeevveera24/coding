import java.util.Scanner;

class Lab2ex3
{
	public static void main(String[] args)
	{
		int i,size,num;

		System.out.println("Enter the size of the array");
		Scanner scan = new Scanner(System.in);
		size = scan.nextInt();
		
		int array[] = new int[size];
		
		System.out.println("Enter the elements of the array");
		for(i=0;i<size;i++)
		{
			array[i] = scan.nextInt();
		}
		
		System.out.println("Enter the number to be found");
		num=scan.nextInt();
		
		search(array,size,num);				
	}
	public static void search(int array[], int size, int num)
	{
		int i,flag=0;
		for(i=0;i<size;i++)
		{
			if(array[i]==num)
				{
					flag=1;
					break;
				}
		}
		if(flag==1)
			System.out.println(num+" found in "+(i+1)+" position");
		else
			System.out.println("Number not found");
	}
}
