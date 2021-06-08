abstract class MITPerson{
	String name;
	private long[] cellNum;
	String [] eMail;
	boolean personType;
	final long getFirstCellNum(){
		return cellNum[0];
	}
	final long getSecondCellNum(){
		return cellNum[1];
	}
	abstract void display();
	static void display(MITPerson[] person){
	}
	MITPerson(String name, long[] cellNum, String[] eMail, boolean personType){
		this.name = name;
		this.cellNum = cellNum;
		this.eMail = eMail;
		this.personType = personType;
	}
	public String toString(){
		return ("Name: " + name );
	}
}
class MITStudent extends MITPerson{
	String usn;
	void display(){
	}
	public String toString(){
		return (super.toString() + "\t" +"username: "+usn);
	}
}
class MITStaff extends MITPerson{
	int staffId;
	void display(){

	}
	public String toString(){
		return (super.toString() + "\t" +"ID: "+staffId);
	}
}