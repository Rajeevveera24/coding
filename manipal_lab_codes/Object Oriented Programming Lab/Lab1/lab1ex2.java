//need to calculate imaginary roots

import java.util.Scanner;
import java.math.*;

class lab1ex2{
	public static void main(String args[]){
		Scanner sc=new Scanner(System.in);
		System.out.println("Enter three numbers");
		float a = sc.nextInt();
		float b = sc.nextInt();
		float c = sc.nextInt();
		Function.root(a,b,c);
	
	}
}
class Function{
	public static void root(float a, float b, float c){
		double x1,x2;
		float d = b*b -4*a*c;
		int k;
		if (d>0)
		k=1;
		else if(d<0)
		k=2;
		else
		k=3;
		switch(k)
		{
			case 1:
			{	System.out.println("Roots are real and distinct");
				x1 = -b + Math.sqrt(Math.abs(d));
				x1/=a;
				x1/=2;				
				x2 = -b - Math.sqrt(Math.abs(d));
				x2/=a;
				x2/=2;
				System.out.println("Roots are "+x1+" and "+x2);
				
			}
			break;
			case 2:
			{
				System.out.println("Roots are imaginary");
			}
			break;
			case 3:
			{	
				System.out.println("Roots are equal");
				x1=-b/(a*2);
				System.out.println("Value of roots is "+x1);
			}
			break;
			default:
			break;
		}
	}

}
