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
		Complex num1 = new Complex(5,6);
		Complex num2 = new Complex(1,2);
		Complex sum = new Complex();
		Complex diff = new Complex();
		System.out.print("The complex numbers are ");
		Complex.display(num1);
		System.out.print(" and ");
		Complex.display(num2);
		System.out.println();
		sum = Complex.add(num1,num2);
		System.out.print("The sum is ");
		Complex.display(sum);
		System.out.println();
		System.out.print("The difference is ");
		diff = Complex.sub(num1,num2);
		Complex.display(diff);
		System.out.println();
	}
}