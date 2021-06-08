import java.util.Scanner;
class Mixer
{
	int arr[];
	Mixer(int size)
	{
		int arr[] = new int[size];
	}
	void accept(int size)
	{
		Scanner scan = new Scanner(System.in);
		System.out.println("Enter the values of the elements of the array in ascending order");
		for(int i=0;i<size;i++)
		{
			arr[i]=scan.nextInt();
			if(i>0 && arr[i]==arr[i-1])
			{
				System.out.println("Element already exists. Enter another value");
				arr[i]=scan.nextInt();
			}
		}
	}
	void display()
	{
		for(int i=0;i<arr.length;i++)
		{
			System.out.println(arr[i]);
		}
	}
	public Mixer mix (Mixer A)
	{
		int i=0,j=0;
		Mixer c = new Mixer(this.arr.length+A.arr.length);

		for(int k=0;k<c.arr.length;k++)
		{
			if(this.arr[i]<A.arr[j])
			{
				c.arr[k]=this.arr[i];
				i++;
			}
			else
			{
				c.arr[k]=A.arr[j];
				j++;
			}
		}
		return c;
	}
	public static void main(String args[])
	{
		int size1,size2;
		Scanner scan = new Scanner(System.in);
		System.out.println("Enter the sizes of the two arrays");
		size1=scan.nextInt();
		size2=scan.nextInt();
		Mixer A = new Mixer(size1);
		Mixer B = new Mixer(size2);
		A.accept(size1);
		System.out.println("The values of elements in first array are:");
		A.display();
		B.accept(size2);
		System.out.println("The values of elements in second array are:");
		B.display();
		A.mix(B);
		A.display();
	}
}
