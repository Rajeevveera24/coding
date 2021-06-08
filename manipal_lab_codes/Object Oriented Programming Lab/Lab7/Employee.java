import java.io.*;
import java.util.Scanner;
class Employee{
	String name;
	int age;
	double grossSalary;
	float takeHomeSalary;
	char grade;
	void input() throws IOException {
		BufferedReader scan = new BufferedReader(new InputStreamReader(System.in));
		System.out.println("Enter name, age, gross salary, take home salary, grade respectively");
		try{
			name = scan.readLine();
		}
		catch(IOException io){
			System.out.println("Exception Thrown "+ io);
		}
		try{
			age = Integer.parseInt(scan.readLine());
		}
		catch(IOException io){
			System.out.println("Exception Thrown "+ io);
		}
		try{
			grossSalary = Double.parseDouble(scan.readLine());
		}
		catch(IOException io){
			System.out.println("Exception Thrown "+ io);
		}
		try{
			takeHomeSalary = Float.parseFloat(scan.readLine());
		}
		catch(IOException io){
			System.out.println("Exception Thrown "+ io);
		}
		try{
			grade = (scan.readLine()).charAt(0);
		}
		catch(IOException io){
			System.out.println("Exception Thrown "+ io);
		}
	}
	void display(){
		System.out.println("Name: "+name);
		System.out.println("Age: "+age);
		System.out.println("Gross Salary: "+grossSalary);
		System.out.println("Take Home Salary: "+takeHomeSalary);
		System.out.println("Grade: "+grade);
	}
	public static void main (String[] args) throws IOException{
		Scanner scan = new Scanner(System.in);
		Employee e[] = new Employee[5];
		int option = 0,i=0;
		do{
			System.out.println("Enter the 1,2,0 to input, display and exit respectively");
			option = scan.nextInt();
			switch(option){
				case 1:{
					e[i] = new Employee();
					e[i].input();
					i++;
				}
				break;
				case 2:{
					System.out.println("Enter the index of record to be displayed");
					int num = scan.nextInt();
					e[num-1].display();
				}
				break;
				default:
				break;
			}

		}while(option!=0 && i<5);
	}
}