import java.util.Scanner;
class Customer{
	private long id;
	private String name;
	private int limit;
	Customer(){
		id = 0;
		name = "Rajeev";
		limit = 0;
	}
	Customer(long id, String name, int limit){
		this.id = id;
		this.name = name;
		this.limit = limit;
	}
	void show(){
		System.out.print("Customer ID: "+ id);
		System.out.print("\tCustomer Name: "+ name);
		System.out.println("\tCustomer limit: "+limit);
	}
	public static void main(String[] args){
		Scanner scan = new Scanner(System.in);
		Customer cust[] = new Customer[5];
		String name;
		int limit;
		long id;
		System.out.println("Enter the values of five customers");
		for(int i=0;i<5;i++){
			System.out.print("Customer ID: ");
			id = scan.nextLong();
			scan.nextLine();
			System.out.print("Customer Name: ");
			name = scan.nextLine();
			System.out.print("Customer limit: ");
			limit = scan.nextInt();
			cust[i] = new Customer(id,name,limit);
		}
		System.out.println("Details of the 5 customers are:");
		for(int i=0;i<5;i++){
			cust[i].show();
		}
	}
}
