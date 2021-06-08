import java.util.*;

class GenStack<T extends Number>{
	Node root;
	GenStack(){
		root = null;
	}
	public static void main(String[] args) {
		GenStack <Integer> stack = new GenStack <Integer> ();
		stack.push_node(10);
		stack.push_node(45);
		stack.push_node(60);
		stack.print();
		stack.pop_node();
		stack.print();
	}

	public void push_node(T ob){
		if(root == null){
			root = new Node(ob);
			//root.next = null;
			return;
		}

		Node temp = root;

		while(temp.next != null){
			temp = temp.next;
		}
		temp.next = new Node(ob);
		//temp.next.next = null;
	}

	public void pop_node(){
		if(root == null){
			return;
		}
		Node temp = root;
		while(temp.next.next!=null){
			temp = temp.next;
		}
		temp.next = null;
	}

	public void print(){
		Node temp = root;
		while(temp!=null){
			System.out.print(temp.ob+"\t");
			temp = temp.next;
		}
		System.out.println();
	}
}

class Node <T extends Number>{
	T ob;
	Node next;

	Node(T ob){
		this.ob = ob;
		next = null;
	}
}
