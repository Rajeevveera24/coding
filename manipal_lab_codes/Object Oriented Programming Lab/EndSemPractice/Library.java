import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

class Library extends JFrame{

	JLabel label1,label2,label3;
	JTextField text1,text2,text3,text4;
	JButton button1,button2;
	int count;

	public static void main(String[] args) {
		SwingUtilities.invokeLater(new Runnable(){
			public void run(){
				new Library();
			}
		});
	}
	Library(){
		Book books[] = new Book[10];
		setSize(180,300);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setLayout(new FlowLayout());

		button1 = new JButton("CREATE");
		button2 = new JButton("SEARCH");
		label1 = new JLabel("Enter Book Details");
		label2 = new JLabel("Enter Book Title to Search");
		label3 = new JLabel("");
		text1 = new JTextField(10);
		text2 = new JTextField(10);
		text3 = new JTextField(10);
		text4 = new JTextField(10);

		add(label1);
		add(text1);
		add(text2);
		add(text3);
		add(button1);
		add(label2);
		add(text4);
		add(button2);
		add(label3);

		setVisible(true);
		button1.addActionListener(new ActionListener(){
			public void actionPerformed(ActionEvent ae){
				books[count++] = new Book(text1.getText(),text2.getText(),Double.parseDouble(text3.getText()));
				remove(label3);
				label3.setText("Book Added");
				text1.setText("");
				text2.setText("");
				text3.setText("");
				add(label3);
				setVisible(true);
			}
		});
		button2.addActionListener(new ActionListener(){
			public void actionPerformed(ActionEvent ae){
				String name = text4.getText();
				remove(label3);
				int found=0;
				for(Book book: books){
					found = 0;
					if(book.author.equals(name)){
						found = 1;
						break;
					}
				}
				if(found == 1){
					label3.setText("Book is found");
				}
				else{
					label3.setText("Book is not found");
				}
				add(label3);
				text4.setText("");
				setVisible(true);
			}
		});
	}
}

class Book{
	double price;
	String title,author;
	Book(String title, String author, double price){
		this.title = title;
		this.author = author;
		this.price = price;
	}
}
