import java.sql.*;

import java.awt.BorderLayout;
import java.awt.EventQueue;

import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.border.EmptyBorder;
import javax.swing.GroupLayout;
import javax.swing.GroupLayout.Alignment;
import javax.swing.JButton;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import javax.swing.JTextField;
import javax.swing.JLabel;
import javax.swing.LayoutStyle.ComponentPlacement;

public class CustomerLogin extends JFrame {

	private JPanel contentPane;
	private JTextField textField;
	JLabel label = new JLabel("");
	int x;
	
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					CustomerLogin frame = new CustomerLogin();
					frame.setVisible(true);
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});
	}

	public CustomerLogin() {
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setBounds(100, 100, 450, 300);
		contentPane = new JPanel();
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
		setContentPane(contentPane);
		
		JButton btnBack = new JButton("Back");
		btnBack.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				dispose();
				MainPage mPage = new MainPage();
				mPage.shell.setVisible(true);
			}
		});
		
		textField = new JTextField();
		textField.setColumns(10);
		
		JButton btnLogin = new JButton("Login");
		btnLogin.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				
				try {
					x = Integer.parseInt(textField.getText());
				
			        try {
					
					        Class.forName("oracle.jdbc.driver.OracleDriver");	
					        Connection con = DriverManager.getConnection("jdbc:oracle:thin:@localhost:1521:ORCL", "system", "rajeev");						
					        Statement stmt = con.createStatement();							        
					        ResultSet rs = stmt.executeQuery("SELECT acc_no FROM account");
					        System.out.println("connected");
					        while (rs.next())
					        {		
					        	if ( x == rs.getInt(1)) {
					        		//System.out.println("Yes!!");
					        		dispose();
					        		Customer C = new Customer();
					        		C.account = x;
					        		C.setVisible(true);
					        	}
					        }	
					        label.setText("Denied Entry");
					        con.close();			
					    } 
			        catch (SQLException ex) {
					        System.out.println(ex);
			
					    }
			        catch (ClassNotFoundException ex) {
			
					        System.out.println(ex);			
					    }
				}
				catch(Exception f) {
					f.printStackTrace();
					label.setText("Enter only Numbers");
				}
			}
					
		});
		
		JLabel lblAccountNumber = new JLabel("Account Number");
		
		GroupLayout gl_contentPane = new GroupLayout(contentPane);
		gl_contentPane.setHorizontalGroup(
			gl_contentPane.createParallelGroup(Alignment.LEADING)
				.addGroup(gl_contentPane.createSequentialGroup()
					.addGroup(gl_contentPane.createParallelGroup(Alignment.LEADING)
						.addGroup(gl_contentPane.createSequentialGroup()
							.addGap(33)
							.addComponent(btnBack))
						.addGroup(gl_contentPane.createSequentialGroup()
							.addGap(49)
							.addComponent(lblAccountNumber, GroupLayout.DEFAULT_SIZE, 98, Short.MAX_VALUE)
							.addGap(18)
							.addGroup(gl_contentPane.createParallelGroup(Alignment.LEADING)
								.addComponent(btnLogin, GroupLayout.PREFERRED_SIZE, 78, GroupLayout.PREFERRED_SIZE)
								.addComponent(textField, GroupLayout.PREFERRED_SIZE, GroupLayout.DEFAULT_SIZE, GroupLayout.PREFERRED_SIZE))))
					.addGap(173))
				.addGroup(gl_contentPane.createSequentialGroup()
					.addGap(179)
					.addComponent(label)
					.addContainerGap(199, Short.MAX_VALUE))
		);
		gl_contentPane.setVerticalGroup(
			gl_contentPane.createParallelGroup(Alignment.LEADING)
				.addGroup(gl_contentPane.createSequentialGroup()
					.addContainerGap()
					.addComponent(btnBack)
					.addGap(35)
					.addComponent(label)
					.addGap(18)
					.addGroup(gl_contentPane.createParallelGroup(Alignment.BASELINE)
						.addComponent(textField, GroupLayout.PREFERRED_SIZE, GroupLayout.DEFAULT_SIZE, GroupLayout.PREFERRED_SIZE)
						.addComponent(lblAccountNumber))
					.addGap(27)
					.addComponent(btnLogin)
					.addContainerGap(80, Short.MAX_VALUE))
		);
		contentPane.setLayout(gl_contentPane);
	}

}
