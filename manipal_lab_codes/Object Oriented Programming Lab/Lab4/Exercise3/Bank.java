import java.util.Scanner;
class BankAccount{
	int type;
	long account_number;
	String name;
	int balance;
	static int rate;
	BankAccount(){
		type =1;
		rate=5;
		name = "Rajeev";
		balance = 0;
		account_number=12345;
	}
	BankAccount(int r,int t,int b,long a_n, String name){
		rate = r;
		type = t;
		balance = b;
		account_number = a_n;
		this.name = name;
	}
	void display(){
		System.out.println("Account Type: "+type);
		System.out.println("Account Number: "+account_number);
		System.out.println("Account Holder Name: "+name);
		System.out.println("Account Balance: "+balance);
		System.out.println("Interest Rate: "+rate);
	}
	static void rate_display(){
		System.out.println("Interest Rate: "+rate);
	}
	void deposit(int amount){
		balance+=amount;
	}
	void withdraw(int amount){
		if(balance<amount)
			System.out.println("Balance not enought to withdraw");
		else{
			balance-=amount;
			System.out.println("Balance after withdrawal is "+balance);
		}
	}
}
class Bank{
	public static void main(String[] args){
		Scanner scan = new Scanner(System.in);
		int type,balance,rate;
		long a_n;
		String name;
		System.out.println("Enter the account detailts");
		System.out.print("Account Type: ");
		type = scan.nextInt();
		System.out.print("Account Number: ");
		a_n = scan.nextLong();
		scan.nextLine();
		System.out.print("Account Holder Name: ");
		name = scan.nextLine();
		System.out.print("Account Balance: ");
		balance = scan.nextInt();
		System.out.print("Interest Rate: ");
		rate = scan.nextInt();
		BankAccount account = new BankAccount(rate,type,balance,a_n,name);
		System.out.println("Enter the amount to be deposited");
		int amt = scan.nextInt();
		account.deposit(amt);
		System.out.println("Enter the amount to be withdrawn");
		int with = scan.nextInt();
		account.withdraw(with);
		System.out.println("The account details are");
		account.display();
		account.rate_display();
	}
}
