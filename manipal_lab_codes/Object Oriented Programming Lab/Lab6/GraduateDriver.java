import java.util.*;
class Person{
	private String name;
	private GregorianCalendar dob;
	Person(String name, GregorianCalendar dob){
		this.name = name;
		this.dob = dob;
	}
	String get_name(){return name;}
	GregorianCalendar get_dob(){return dob;}
}
class CollegeGraduate extends Person{
	private float gpa;
	private int grad_year;
	CollegeGraduate(String name, GregorianCalendar dob, float gpa, int grad_year ){
		super(name,dob);
		this.gpa = gpa;
		this.grad_year = grad_year;
	}
	float get_gpa(){return gpa;}
	int get_grad_year(){return grad_year;}
}
class GraduateDriver{
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		CollegeGraduate cg;
		String name;
		GregorianCalendar dob;
		int db[] = new int [3];
		float gpa;
		int grad_year;
		System.out.println("Enter the details of the College Graduate");
		System.out.print("Name: ");
		name = scan.nextLine();
		System.out.print("Date of Birth (dd mm yy) : ");
		db[0] = scan.nextInt();//System.out.print(db[0]);
		db[1] = scan.nextInt();//System.out.print(db[0]);
		db[2] = scan.nextInt();//System.out.print(db[0]);
		dob = new GregorianCalendar(db[1],db[0],db[2]);
		System.out.print("GPA: ");
		gpa = scan.nextFloat();
		System.out.print("Year of Graduation: ");
		grad_year = scan.nextInt();
		cg = new CollegeGraduate(name,dob,gpa,grad_year);			
		System.out.println("Details of College Graduate are:");
		name = cg.get_name();
		dob = cg.get_dob();
		gpa = cg.get_gpa();
		grad_year = cg.get_grad_year();	
		System.out.println("Name: "+name);
		System.out.println("Date of Birth (dd mm yy) : "+dob.get(Calendar.DATE)+"/"+dob.get(Calendar.MONTH)+"/"+dob.get(Calendar.YEAR));
		System.out.println("GPA: "+gpa);
		System.out.println("Year of Graduation: "+grad_year);
	}
}