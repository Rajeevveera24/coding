import java.util.Scanner;
class Complex
{
	int real,imaginary;
	Complex()
	{
		real=0;
		imaginary=0;
	}
	Complex(int a,int b)
	{
		real=a;
		imaginary=b;
	}
	public static void display(Complex a)
	{
		System.out.print(a.real+" + i"+a.imaginary);
	}
	public static Complex add(Complex a, Complex b)
	{
		Complex c = new Complex();
		c.real = a.real + b.real;
		c.imaginary = 	a.imaginary + b.imaginary;
		return c;
	}
	public static Complex sub(Complex a, Complex b)
	{
		Complex c = new Complex();
		c.real = a.real - b.real;
		c.imaginary = 	a.imaginary - b.imaginary;
		return c;
	}
}
class Complex_number
{
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		Complex num1 = new Complex();
		Complex num2;
		System.out.println("Enter the real and imaginary values");
		int a = sc.nextInt();
		int b =sc.nextInt();
		num2 = new Complex(a,b);
		System.out.print("The default complex number is ");
		Complex.display(num1);
		System.out.print(" and the parametrized complex number is ");
		Complex.display(num2);
		System.out.println();
	}
}