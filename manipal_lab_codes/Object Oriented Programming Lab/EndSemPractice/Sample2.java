import java.util.*;
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

class Sample2{

	JFrame jfrm;
	JButton start,reset,stop;
	JLabel put,got;
	int i=1,valueSet;
	int count=0;
	int control = 0;

	Sample2(){

		Q q = new Q();
		Producer p = new Producer(q);
		Consumer c = new Consumer(q);

		jfrm = new JFrame();
		jfrm.setSize(300,400);
		jfrm.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		jfrm.setLayout(new FlowLayout());

		start = new JButton("Start");
		reset = new JButton("reset");
		stop = new JButton("Stop");
		put = new JLabel("");
		got = new JLabel("");

		jfrm.add(start);
		jfrm.add(stop);
		jfrm.add(reset);
		jfrm.add(put);
		jfrm.add(got);

		start.addActionListener(new ActionListener(){
			public void actionPerformed(ActionEvent ae){
				if(count == 0){
					count++;
					valueSet = 0;
					control = 1;
					p.t.start();
					c.t.start();
				}
				else{
					control = 1;
					try{
						Thread.sleep(500);
					}
					catch(InterruptedException e){

					}
				}
			}
		});

		reset.addActionListener(new ActionListener(){
			public void actionPerformed(ActionEvent ae){
				i = 1;
			}
		});

		stop.addActionListener(new ActionListener(){
			public void actionPerformed(ActionEvent ae){
				control = 0;
			}
		});

		jfrm.setVisible(true);
	}

	public static void main(String[] args) {
		SwingUtilities.invokeLater(new Runnable(){
			public void run(){
				new Sample2();
			}
		});
	}

	class Q{
		int n;
		synchronized int get(){	
			if(control != 0){
				if(valueSet == 0){
					try{
						wait();
						Thread.sleep(500);
					}
					catch(InterruptedException e){

					}
				}
				valueSet = 0;
				got.setText("Got: " + n);
				notify();
				return n;
			}
			return n;
		}
		synchronized void put(int n){
			if(control != 0){
				if(valueSet==1){
					try{
						wait();
						Thread.sleep(500);
					}
					catch(InterruptedException e){

					}
				}
				valueSet = 1;
				this.n = n;
				put.setText("Put: " +n);
				notify();
			}
		}
	}
	class Producer implements Runnable{
		Q q;
		Thread t;
		Producer(Q q){
			this.q = q;
			t = new Thread(this,"Producer");
		}
		public void run(){
			while(true){
				q.put(i++);
			}
		}
	}
	class Consumer implements Runnable{
		Q q;
		Thread t;
		Consumer(Q q){
			this.q = q;
			t = new Thread(this,"Consumer");
		}
		public void run(){
			while(true){
				q.get();
			}
		}
	}
}