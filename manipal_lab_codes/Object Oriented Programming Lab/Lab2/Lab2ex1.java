import java.util.Scanner;

class Lab2ex1
{
	public static void main(String[] args)
	{
		int i,j,size;
		
		System.out.println("Enter the size of the array");
		Scanner scan = new Scanner(System.in);
		size = scan.nextInt();
		
		int array[] = new int[size];
		
		System.out.println("Enter the elements of the array");
		for(i=0;i<size;i++)
		{
			array[i] = scan.nextInt();
		}
		
		for(i=0;i<size;i++)
			for(j=0;j<size-i-1;j++)
			{
				if(array[j]>array[j+1])
					{
						array[j]+=array[j+1];
						array[j+1]=array[j] - array[j+1];
						array[j]=array[j] - array[j+1];
					}
			}
			
		System.out.println("Elements of the array in ascending order are:");
		for(i=0;i<size;i++)
		{
			System.out.print(array[i]+"\t");
		}
		System.out.println();
		
		for(i=0;i<size;i++)
			for(j=0;j<size-i-1;j++)
			{
				if(array[j]<array[j+1])
					{
						array[j]+=array[j+1];
						array[j+1]=array[j] - array[j+1];
						array[j]=array[j] - array[j+1];
					}
			}
			
		System.out.println("Elements of the array in descending order are:");
		for(i=0;i<size;i++)
		{
			System.out.print(array[i]+"\t");
		}
		System.out.println();			
	}
}
