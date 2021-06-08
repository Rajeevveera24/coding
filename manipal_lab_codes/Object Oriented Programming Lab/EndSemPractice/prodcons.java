import java.lang.*;
class Q{
	int n;
	boolean valueSet = false;

	synchronized int get(){
		if(!valueSet){
			try{
				wait();
				Thread.sleep(1000);
			}
			catch(InterruptedException e){

			}
		}
		System.out.println("Got :"+ n);
		valueSet = false;
		notify();
		return n;
	}
	synchronized void put(int n){
		if(valueSet){
			try{
				wait();
				Thread.sleep(1000);
			}
			catch(InterruptedException e){

			}
		}
		this.n = n;
		System.out.println("Put :" + n);
		valueSet = true;
		notify();
	}
}
class Producer implements Runnable{
	Q q;
	Thread t;
	Producer(Q q){
		this.q = q;
		t = new Thread(this, "Producer");
	}
	public void run(){
		int i = 1;
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
class prodcons{
	public static void main(String[] args) {
		Q q = new Q();
		Consumer c = new Consumer(q);
		Producer p = new Producer(q);
		c.t.start();
		p.t.start();
	}
}