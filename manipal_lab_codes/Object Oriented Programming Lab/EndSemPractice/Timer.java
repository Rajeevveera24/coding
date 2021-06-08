import java.util.*;
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class Timer{
	long time;
	JFrame jfrm;
	JButton start,stop;
	JLabel message;

	Timer(){

		jfrm = new JFrame("Time");
		jfrm.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		jfrm.setLayout(new BorderLayout());
		jfrm.setSize(400,600);
		jfrm.setVisible(true);

		start = new JButton("Start");
		stop = new JButton("Stop");
		message = new JLabel();
		message.setText("Press Start to begin timing");

		jfrm.add(start,BorderLayout.WEST);
		jfrm.add(stop,BorderLayout.EAST);
		jfrm.add(message,BorderLayout.CENTER);

		start.addActionListener(new ActionListener(){
			public void actionPerformed(ActionEvent ae){
				time = System.currentTimeMillis();
				message.setText("<html>"+"Timer Running. <br> Press Stop to stop timing");
			}
		});
		stop.addActionListener(new ActionListener(){
			public void actionPerformed(ActionEvent ae){
				time = System.currentTimeMillis() - time;
				message.setText("Time elapsed is "+ time/1000 + "." + (time - time/1000)%1000 +  " seconds");
			}
		});
	}


	public static void main(String[] args) {
		SwingUtilities.invokeLater(new Runnable(){
			public void run(){
				new Timer();
			}
		});
	}
}

