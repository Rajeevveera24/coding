import java.util.Scanner;
class Arr <T> {
	T ob[];
	Arr (T o[]){
		ob = o;
	}
	void swap(int a, int b){
		T temp = ob[a];
		ob[a] = ob[b];
		ob[b] = temp;
		System.out.println("Swapped");
	}
	void print(){
		System.out.print("The elements of array are:\t");
		for(T i : ob ){
			System.out.print(i+"\t");
		}
		System.out.println();
	}
}
class Ex1{
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		Integer a[] = new Integer[5];
		String s[] = new String[5];
		System.out.println("Enter 5 integers");
		for(int i=0;i<5;i++){
			a[i] = scan.nextInt();
		}
		Arr <Integer> iArr = new Arr<Integer>(a);
		iArr.print();
		System.out.println("Enter the two positions to be swapped");
		int b = scan.nextInt();
		int c = scan.nextInt();
		iArr.swap(b-1,c-1);
		iArr.print();
		System.out.println("Enter 5 strings");
		scan.nextLine();
		for(int i=0;i<5;i++){
			s[i] = scan.nextLine();
		}
		Arr <String> sArr = new Arr<String>(s);
		sArr.print();
		System.out.println("Enter the two positions to be swapped");
		b = scan.nextInt();
		c = scan.nextInt();
		sArr.swap(b-1,c-1);
		sArr.print();
	}
}