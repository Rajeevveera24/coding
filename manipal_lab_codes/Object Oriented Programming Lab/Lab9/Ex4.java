class Ex4{
	public static void main(String[] args) {
		int a,b;
		a = 5;
		b = 6;
		Gen<Integer>igen = new Gen<Integer>(a);
		Gen<Double>dgen = new Gen<Double>((double)b);
		if(dgen.compare(igen)){
			System.out.println("b is larger");
		}
		else{
			System.out.println("a is larger");
		}
	}
}
class Gen<T extends Number>{
	T ob;
	Gen(T ob){
		this.ob = ob;
	}
	boolean compare(Gen<?> ob){
		if(this.ob.doubleValue()>ob.ob.doubleValue()){
			return true;
		}
		return false;
	}
}