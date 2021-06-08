import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import java.applet.*;
import java.util.*;
import java.lang.*;

class Sample1{

	JFrame jfrm;
	JButton banner,rectangle,tables;
	JLabel display;
	Thread t1,t2,t3;
	String str = new String("THIS IS OOP LAB EXAM ");

	Sample1(){

		jfrm = new JFrame("Sample1");
		jfrm.setLayout(new FlowLayout());
		jfrm.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		jfrm.setSize(400,800);

		jfrm.setVisible(true);
		banner = new JButton("Banner");
		rectangle = new JButton("Rectangle");
		tables = new JButton("Tables");
		display = new JLabel("");

		jfrm.add(banner);
		jfrm.add(rectangle);
		jfrm.add(tables);
		jfrm.add(display);

		banner.addActionListener(new ActionListener (){
			public void actionPerformed(ActionEvent ae){
				while(true){
					display.setText(str);
					char ch = str.charAt(0);
					str = str.substring(1,str.length());
					str += ch;
				}
			}
		});
		//tables.addActionListener(this);
		//rectangle.addActionListener(this);

	}

	public static void main(String[] args) {
		new Sample1();
	}
}