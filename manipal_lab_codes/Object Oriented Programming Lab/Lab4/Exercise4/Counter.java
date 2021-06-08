class Counter{
	static int count=0;
	Counter(){
		count+=1;
	}
	static void showCount(){
		System.out.println("The number of objects of type Counter created at present is "+count);
	}
	public static void main(String args[]){
		Counter c1 = new Counter();
		Counter c2 = new Counter();
		Counter.showCount();
		Counter c3 = new Counter();
		Counter.showCount(); 
	}
}