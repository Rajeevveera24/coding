import java.util.Scanner;
interface Stack{
	int push(int a[], int d,int t, int s);
	int pop(int a[], int t);
}
class FixedStack implements Stack{
	public int push(int [] array, int data, int top, int size){
		if(top>=size-1){
			System.out.println("Stack Full");
			return top;
		}
		else{
			top++;
			array[top] = data;
			return top;
		}
	}
	public int pop(int [] array, int top){
		if(top==-1){
			System.out.println("Stack Empty");
			return top;
		}
		else{
			System.out.println("Element popped is "+array[top]);
			top--;
			return top;
		}
	}
}
class DynamicStack implements Stack{
	public int push(int [] array ,int data, int top, int size){
		if(top>=size-1){
			int arr[] = new int[size+1];
			for(int i=0;i<size;i++){
				arr[i] = array[i];
			}
			array = new int[size++];
			for(int i=0;i<size;i++){
				array[i] = arr[i];
			}
		}
		top++;
		array[top] = data;
		return size;
	}
	public int pop(int [] array, int top){
		if(top==-1){
			System.out.println("Stack Empty");
			return top;
		}
		else{
			System.out.println("Element popped is "+array[top]);
			top--;
			return top;
		}
	}
}
class StackDriver{
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int arr1[];
		int arr2[];
		int top=-1,size=5;
		Stack s1 = new FixedStack();
		Stack s2 = new DynamicStack();
		System.out.println("Enter the size of Fixed Stack");
		arr1= new int[size];
		int option=1;
		int data;
		while(option!=0){
			System.out.print("Enter 1,2,3,0 to push,pop,display and exit respectively: ");
			option = scan.nextInt();
			switch(option){
				case 1:{ data = scan.nextInt(); top = s1.push(arr1,data,top,size);}
				break;
				case 2:{ top = s1.pop(arr1,top);}
				break;
				case 3:{for(int i=top;i>=0;i--){System.out.println(arr1[i]);}}
				break;
				default: break;
			}
		}
		top=-1;
		arr2 = new int[100];
		System.out.println("Entering DynamicStack");
		do{
			System.out.print("Enter 1,2,3,0 to push,pop,display and exit respectively: ");
			option = scan.nextInt();
			switch(option){
				case 1:{ 	data = scan.nextInt(); 
							int top1=top;
							top = s2.push(arr2,data,top,size);
							if(top1!=top-1){
								size++;
								top--;
							}
						}
				break;
				case 2:{ top = s2.pop(arr2,top);}
				break;
				case 3:{for(int i=top;i>=0;i--){System.out.println(arr2[i]);}}
				break;
				default: break;
			}
		}while(option!=0);	
	}
}