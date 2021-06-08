import java.util.Scanner;
class Area{
	public static void main(String[] args) {
		Rectangle r = new Rectangle();
		Square s = new Square();
		Triangle t = new Triangle();
		int a,b;
		Scanner scan = new Scanner(System.in);
		System.out.println("Enter the height and width");
		a = scan.nextInt();
		b = scan.nextInt();
		System.out.println("Area of Rectangle is "+r.area(a,b));
		System.out.println("Area of Triangle is "+t.area((float)a,(float)b));
		System.out.println("Enter the size of sides of square");
		a = scan.nextInt();
		System.out.println("Area of Square is "+s.area(a));
	}
}
abstract class Figure{
	int a,b;
	int area(int a,int b){return a*b;}
}
class Rectangle extends Figure{
}
class Square{
	int area(int a){return a*a;}
}
class Triangle{
	double area(float a, float b){return 0.5*a*b;}
}