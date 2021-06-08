import java.util.Scanner;
import java.io.*;
class SeatsFilledException extends Exception{
	public SeatsFilledException(){
			System.out.println("Seats Filled");
	}
}
class Student{
	int regnum;
	void set_regnum(int num) throws SeatsFilledException{
		if(num%100 >25){
			throw new SeatsFilledException(); 
		}
		else{
			regnum = num;
		}
	}
	public static void main(String[] args) throws SeatsFilledException{
		Scanner scan = new Scanner(System.in);
		Student s = new Student();
		System.out.print("Enter the registration number: ");
		int reg = scan.nextInt();
		s.set_regnum(reg);
	}
}