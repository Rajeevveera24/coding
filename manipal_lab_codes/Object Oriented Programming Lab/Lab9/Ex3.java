import java.util.Scanner;
class Node<T>{
	T ob;
	Node(T ob){
		this.ob = ob;
	}
	Node next;
}
class List <T>{
	Node root;
	List(){
		root = null;
	}
	public void add(T ob){
		if(root==null){
			root = new Node(ob);
			return;
		}
		Node i = root;
		while(i.next!=null){
			i=i.next;
		}
		i.next = new Node(ob);
		i.next.next=null;
	}
	public void remove(int i){
		if(root==null){
			return;
		}
		int count=1;
		Node n = root;
		root = n;
		while(count++<i){
			n=n.next;
		}
		if(n.next==null){
			n=null;
		}
		else{
			n=n.next.next;
		}
	}
	public void print(){
		System.out.println();
		Node n = root;
		while(n!=null){
			System.out.print(n.ob+"\t");
			n = n.next;
		}
		System.out.println();
	}
}
class Ex3{
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		List <Integer>li = new List<Integer>();
		List <Double>ld = new List<Double>();
		int data;
		Double Ddata;
		System.out.print("Enter 5 numbers: ");
		for(int i=0;i<5;i++){
			data = scan.nextInt();
			li.add(data);
		}
		System.out.print("Enter the position to be removed: ");
		data = scan.nextInt();
		li.remove(data);
		li.print();
		System.out.print("Enter 5 doubles: ");
		for(int i=0;i<5;i++){
			Ddata = scan.nextDouble();
			ld.add(Ddata);
		}
		System.out.print("Enter the position to be removed: ");
		data = scan.nextInt();
		ld.remove(data);
		ld.print();
	}
}
