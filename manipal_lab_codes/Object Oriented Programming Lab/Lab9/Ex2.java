import java.util.Scanner;
class Stack<T>{
	public <T> int push (T [] array, T data, int top, int size){
		if(top>=size-1){
			System.out.println("Stack Full");
			return top;
		}
		else{
			top++;
			array [top] = data;
			return top;
		}
	}
	public <T> int pop(T [] array, int top){
		if(top==-1){
			System.out.println("Stack Empty");
			return top;
		}
		else{
			System.out.println("Element popped");
			top--;
			return top;
		}
	}
}
class Student{
	int roll;
	Student(int roll){
		this.roll = roll;
	}
}
class Employee{
	String Name;
	Employee(String Name){
		this.Name = Name;
	}
}
class Ex2{
	public static void main(String[] args){
		Scanner scan = new Scanner(System.in);
		Student s[] = new Student[5];
		int top=-1,size=5,option=1,data;
		Student t;
		Stack<Student> Stack1 = new Stack<Student>();
		while(option!=0){
			System.out.print("\nEnter 1,2,3,0 to push,pop,display and exit respectively: ");
			option = scan.nextInt();
			switch(option){
				case 1:{
					System.out.println("Enter roll number");
					data = scan.nextInt();
					t = new Student(data);
					top = Stack1.push(s,t,top,size);
				}
				break;
				case 2:{ top = Stack1.pop(s,top);}
				break;
				case 3:{for(int i=0;i<=top;i++){System.out.print(s[i].roll+"\t");}}
				break;
				default: break;
			}
		}
		top=-1;
		String Name;
		Employee e[] = new Employee[5]; 
		Employee f;
		Stack<Employee> Stack2 = new Stack<Employee>();
		System.out.println("Entering Employee");
		do{
			System.out.print("\nEnter 1,2,3,0 to push,pop,display and exit respectively: ");
			option = scan.nextInt();
			switch(option){
				case 1:{ 
						System.out.print("Enter Name: ");
						scan.nextLine();
						Name = scan.nextLine(); 
						f = new Employee(Name);
						top = Stack2.push(e,f,top,size);
				}
				break;
				case 2:{ top = Stack2.pop(e,top);}
				break;
				case 3:{for(int i=0;i<=top;i++){System.out.print(e[i].Name+"\t");}}
				break;
				default: break;
			}
		}while(option!=0);
	}
}