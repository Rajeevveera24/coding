import java.awt.*; 
import java.awt.event.*; 
import javax.swing.*;

class swing extends JFrame{
	JTextField text;
	JLabel label;
	JButton button;

	swing(){
		setSize(300,400);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

		setVisible(true);
		text = new JTextField("Enter name here:");
		label = new JLabel("Hello");
		button = new JButton("Click here to see magic");

		setLayout(new FlowLayout());

		add(text);
		add(label);
		add(button);

		button.addActionListener(new ActionListener(){
			public void actionPerformed(ActionEvent ae){
				display();
			}
		});
	}

	void display(){
		String name = (text.getText().split(":"))[1];
		label.setText("Hello, "+name);
	}

	public static void main(String[] args) {
		SwingUtilities.invokeLater(new Runnable(){
			public void run(){
				new swing();
			}
		});
	}
}