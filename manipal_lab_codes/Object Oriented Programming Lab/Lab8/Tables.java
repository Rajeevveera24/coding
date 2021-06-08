class NewThread extends Thread{
	int n;
	NewThread(int n){
		super("Tables Thread");
		this.n  = n;
	}
	public void run(){
		try{
			for(int i=0;i<=10;i++){
				System.out.println(n+"x"+i+"="+n*i);
				Thread.sleep(500);
			}
		}
		catch(InterruptedException e){
			System.out.println("Demo Interrupted");
		}
		System.out.println("Exiting "+n+" tables");
	}
}
class Tables{
	public static void main(String[] args) throws InterruptedException {
		NewThread t1 = new NewThread(5);
		NewThread t2 = new NewThread(7);
		t1.start();
		t1.join();
		t2.start();
		t2.join();
	}
}