import java.util.Scanner;
class IntArr{
	int[] arr;
	IntArr(){
		int arr[]= new int[3];
		for(int  i=0;i<3;i++)
			this.arr[i] = 0;
	}
	IntArr(int array[]){
		this.arr = new int[array.length];
		for(int i=0;i<array.length;i++)
			arr[i]=array[i];
	}
	static void display(IntArr arr1){
		for(int i=0;i<arr1.arr.length;i++)
			System.out.print(arr1.arr[i]+"\t");
	}
	void search(int num){
		int flag=0;
		for(int i=0;i<this.arr.length;i++){
			if(num==this.arr[i]){
				System.out.println("Number found in "+(i+1)+" position");
				flag=1;
				break;
			}
		}
		if(flag==0)
			System.out.println("Number not found in array");
	}
	static void compare(IntArr a1, IntArr a2){
		int flag=1;
		for(int i=0; i<a1.arr.length;i++){
			if(a1.arr.length!=a2.arr.length){
				flag=0;
				break;
			}
			if(a1.arr[i]!=a2.arr[i]){
				flag=0;
				break;
			}
		}
		if(flag==1)
			System.out.print("Arrays are equal\n");
		else
			System.out.print("Arrays are not equal\n");
	}
	public static void main(String[] args){
		Scanner scan = new Scanner(System.in);
		int a[],b[];
		System.out.println("Enter the sizes of the two arrays");
		int size1 = scan.nextInt();
		int size2 = scan.nextInt();
		a = new int[size1];
		b = new int[size2];
		System.out.println("Enter the elements of the first array");
		for(int i=0;i<size1;i++)
			a[i] = scan.nextInt();
		IntArr a1 = new IntArr(a);
		//for(int i=0;i<a.length;i++)
		//	System.out.print(a[i]+"\t");
		//System.out.println();
		System.out.println("Enter the elements of the second array");
		for(int i=0;i<size2;i++)
			b[i] = scan.nextInt();
		IntArr a2 = new IntArr(b);
		//for(int i=0;i<b.length;i++)
		//	System.out.print(b[i]+"\t");
		//System.out.println();
		System.out.print("Elements of first array are:\t");
		IntArr.display(a1);
		System.out.println();
		System.out.print("Elements of second array are:\t");
		a2.display(a2);
		System.out.println();
		IntArr.compare(a1,a2);
		System.out.println("Enter the number to be searched in first array");
		int num = scan.nextInt();
		a1.search(num);
	}
}
