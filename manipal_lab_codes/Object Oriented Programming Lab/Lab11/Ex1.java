import java.awt.*; 
import java.awt.event.*; 
import javax.swing.*;

class Ex1 extends JFrame{ 

    JTextField first,second; 
    JButton b;
    JLabel n1,n2,n3,n4;
    public static void main(String args[]) {
        SwingUtilities.invokeLater(new Runnable(){
            public void run(){
                new Ex1();
            }
        });
    }
 
    Ex1() { 
        setSize(225,300);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        JLabel fst = new JLabel("first number:"); 
        JLabel scnd = new JLabel("second number:");
        
        first = new JTextField(8); 
        second = new JTextField(8);
        
        b=new JButton("compute");
        n1=new JLabel("Sum is :      ");
        n2=new JLabel("Difference is :      ");
        n3=new JLabel("Product is :      ");
        n4=new JLabel("Quotient is :      ");
        setLayout(new FlowLayout());
     
        add(fst); add(first);
        add(scnd); add(second); 
             
        add(b); 
        add(n1);
        add(n2);
        add(n3);
        add(n4);
      
        b.addActionListener(new ActionListener() {
                public void actionPerformed(ActionEvent ae)
     		     {compute(); }
                }); 
       setVisible(true);
    } 
    void compute(){
        int a,b;
        a=Integer.parseInt(first.getText());
        b=Integer.parseInt(second.getText());
        n1.setText("Sum is :             "+(a+b));
        n2.setText("Difference is :          "+(a-b));
        n3.setText("Product is :            "+(a*b));
        n4.setText("Quotient is :           "+(a/b));
    }
}