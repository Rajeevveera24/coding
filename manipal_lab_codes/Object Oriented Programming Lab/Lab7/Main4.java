import java.util.Scanner;
public class Main4{
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		ByTwos bt  = new ByTwos();
		int num;
		num = bt.reset();
		int option;
		do{
			System.out.print("Enter 0,1,2,3 to exit, get next, reset and set start respectively: ");
			option = scan.nextInt();
			switch(option){
				case 1:{
					num  = bt.GetNext(num);
					System.out.println("Next Number is: "+num);
				}
				break;
				case 2:{
					num = bt.reset();
				}
				break;
				case 3:{
					System.out.print("Enter the number: ");
					num = scan.nextInt();
					bt.setStart(num);
				}
			}
		}while(option!=0);
	}
}
interface Series{
	int GetNext(int num);
	int reset();
	void setStart(int a);
}
class ByTwos implements Series{
	public int GetNext(int num){
		num+=2;
		return num;
	}
	public int reset(){
		System.out.println("Series has been reset");
		return 0;
	}
	public void setStart(int num){
		System.out.println("Start of series has been set to "+num);
	}
}