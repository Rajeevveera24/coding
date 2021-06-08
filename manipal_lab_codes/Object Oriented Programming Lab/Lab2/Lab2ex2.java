import java.util.Scanner;

class Lab2ex2
{
	public static void main(String[] args)
	{
		int i,size,num,pos;
		Scanner scan = new Scanner(System.in);
		
		System.out.println("Enter the size of the array");
		size = scan.nextInt();
		
		int array[] = new int[size+1];
		
		System.out.println("Enter the elements of the array");
		for(i=0;i<size;i++)
		{
			array[i] = scan.nextInt();
		}
		
		System.out.println("Current array is");
		display(array,size);	
		
		System.out.println("Enter the number to be inserted along with the position");
		num=scan.nextInt();
		pos=scan.nextInt();
		
		for(i=size;i>=pos;i--)
			array[i]=array[i-1];
		array[pos-1] = num;
		
		System.out.println("Current array is");
		display(array,size+1);
		
		System.out.println("Enter the position to be deleted");
		pos=scan.nextInt();
		
		for(i=pos-1;i<size;i++)
			array[i]=array[i+1];
		
		System.out.println("Current array is");
		display(array,size);	
		
	}
	public static void display(int array[], int size)
	{
		int i;
		for(i=0;i<size;i++)
			System.out.print(array[i]+"\t");
		System.out.println();
	}
}
