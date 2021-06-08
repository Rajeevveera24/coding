//lab1ex1

import java.util.Scanner;

class Sample{
	public static void main(String args[]){
		Scanner sc=new Scanner(System.in);
		System.out.println("Enter three numbers");
		int a = sc.nextInt();
		int b = sc.nextInt();
		int c = sc.nextInt();
		Function.largest(a,b,c);
	
	}
}
class Function{
	public static void largest(int a, int b, int c){
		if(a>b && a>c)
			System.out.println("Largest number is "+a);
		else if (b>a && b>c) 
			System.out.println("Largest number is "+b);
		else
			System.out.println("Largest number is "+c); 
	}
}
