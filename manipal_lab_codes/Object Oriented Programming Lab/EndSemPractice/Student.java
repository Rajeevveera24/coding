import java.util.*;
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

class Student{
	String name;
	int rollno;
	double cgpa;
	Student(String name, int rollno, double cgpa) throws IncorrectGPAException,IncorrectNameException {
			if(cgpa>10)
				throw new IncorrectGPAException();

			this.name = name;
			this.rollno = rollno;
			this.cgpa = cgpa;
	}

	public static void main(String[] args) throws IncorrectGPAException{
		new Main();
	}
}
class IncorrectGPAException extends Exception{
	public void IncorrectGPAException(){
		System.out.println("Cgpa cannot exceed 10");
	}
}
class IncorrectNameException extends Exception{
	public void IncorrectNameException(){
		System.out.println("Enter Proper Name");
	}
}
class Main extends JFrame{
	int count = 0, count1 = 0;
	JButton sort,search;
	JLabel roll;
	JTextField text;
	JLabel present;
	JLabel sortedstudent;
	Main(){
		Student s[] = new Student[3];

		try{

			s[0] = new Student("ABC",10,9.5);
			s[1] = new Student("CDE",59,7.8);
			s[2] = new Student("Qwerty",60,9);
		}
		catch(Exception e){
			System.out.println("Exception caught"); 
		}

		setSize(400,300);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setLayout(new FlowLayout());

		sort = new JButton("Sort");
		text = new JTextField(10);
		search = new JButton("search");
		roll = new JLabel("Roll no");
		add(sort);
		add(roll);
		add(text);
		add(search);
		setVisible(true);
		sort.addActionListener(new ActionListener(){
			public void actionPerformed (ActionEvent ae){
				for(int i=0;i<3;i++){
					for(int j=0;j<i;j++){
						if(s[i].cgpa>s[j].cgpa){
							Student temp = s[i];
							s[i] = s[j];
							s[j] = temp;
						}
					}
				}
				String sorted = new String("<html>");
				for(int i=0;i<3;i++){
					sorted += s[i].cgpa +"  "+ s[i].name + "<br>"; 
				}
				if(count1>0){
					remove(sortedstudent);
				}
				else{
					count1 = 1;
				}
				sortedstudent = new JLabel();
				sortedstudent.setText(sorted);
				add(sortedstudent);
				setVisible(true);
			}
		});
		search.addActionListener(new ActionListener(){
			public void actionPerformed(ActionEvent ae){

				int a = Integer.parseInt(text.getText());
				int j = 0;
				if(count>0){
					remove(present);
				}
				else{
					count++;
				}

				for(int i=0;i<3;i++){
					if(s[i].rollno == a){
						j = 1;
						break;
					}
				}
				if(j==1){
					present = new JLabel("The student is present in class");
					
				}
				else{
					present = new JLabel("The student is not present in class");
				}
				add(present);
				setVisible(true);
			}
		});
	}
}