import java.util.*;
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

class GenStack<T extends Number>{

	Node root;
	
	GenStack(){
		root = null;
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

	public void print(){ // This method is meaningless in the context of Swings...
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
class StackSwing{
	JFrame jfrm;
	JButton add,remove,print;
	JTextField number;
	JLabel message,display;
	GenStack <Integer> stack;

	StackSwing(){

		stack = new GenStack <Integer> ();

		jfrm = new JFrame("Generic Stack");
		jfrm.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		jfrm.setLayout(new FlowLayout());
		jfrm.setSize(300,400);

		add = new JButton("Add");
		remove = new JButton("Remove");
		print = new JButton("Print");
		number = new JTextField(8);
		message = new JLabel("Enter Number to be added");
		display = new JLabel("");

		jfrm.add(message);
		jfrm.add(number);
		jfrm.add(add);
		jfrm.add(remove);
		jfrm.add(print);
		jfrm.add(display);

		jfrm.setVisible(true);

		add.addActionListener( new ActionListener(){
			public void actionPerformed(ActionEvent ae){
				stack.push_node(Integer.parseInt(number.getText()));
				number.setText("");
				display.setText("Number added to linked list");
				jfrm.setVisible(true);
			}
		});

		remove.addActionListener(new ActionListener(){
			public void actionPerformed(ActionEvent ae){
				stack.pop_node();
				display.setText("Top number popped from linked list");
				jfrm.setVisible(true);
			}
		});

		print.addActionListener(new ActionListener(){
			public void actionPerformed(ActionEvent ae){
				String msg = new String("Number in Linked List: ");
				msg += stack.root.ob;
				Node temp = stack.root.next;
				while(temp != null){
					msg += " " + temp.ob;
					temp = temp.next;
				}				
				display.setText(msg);
				jfrm.setVisible(true);
			}
		});

	}
	public static void main(String[] args) {
		new StackSwing();
	}
}