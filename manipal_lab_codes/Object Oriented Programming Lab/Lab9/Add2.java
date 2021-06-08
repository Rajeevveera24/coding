import java.util.Scanner;
class Add2{
	public static void main(String[] args){
		Scanner scan = new Scanner(System.in);
		double array[] = new double[3];
		String string[] = new String[3];
		System.out.println("Enter 3 Numbers");
		for(int i=0;i<3;i++){
			array[i] = scan.nextDouble();
		}
		System.out.println(compare(array[0],array[1],array[2])+" is the largest");
		System.out.println("Enter three strings");
		scan.nextLine();
		for(int i=0;i<3;i++){
			string[i] = scan.nextLine();
		}
		System.out.println(compare(string[0],string[1],string[2])+" is the largest");
	}
	static <T extends Comparable<T>> T compare(T a,T b,T c){
		T max  = a;
		if(b.compareTo(a)>0){
			max = b;
		}
		if(c.compareTo(max)>0){
			max = c;
		}
		return max;
	}
}