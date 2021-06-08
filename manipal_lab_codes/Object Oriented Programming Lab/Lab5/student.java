import java.util.*;
class student{
	String regnum;
	String fullname;
	GregorianCalendar doj;
	short semester;
	float gpa,cgpa;
	void calc_reg(String num, int year){
			this.regnum = year + num;
	}		
	student(){
		this.regnum = "40";
		this.fullname = "Rajeev Veeraraghavan";
		this.doj = new GregorianCalendar(17,07,18);
		this.semester = 3;
		this.gpa = 9.64F;
		this.cgpa = 9.73F;
		calc_reg(this.regnum, this.doj.get(Calendar.YEAR));
	}
	student(String regnum, String fullname, int doj[], short semester,float gpa, float cgpa){
		this.regnum=regnum;
		this.fullname=fullname;
		this.doj = new GregorianCalendar(doj[2],doj[1],doj[0]);
		this.semester=semester;
		this.gpa=gpa;
		this.cgpa=cgpa;
		calc_reg(this.regnum, this.doj.get(Calendar.YEAR));
	}
	void display(){
		System.out.println("Registration Number: "+regnum);
		System.out.println("Name: "+fullname);
		System.out.print("Date of Joining: ");
		System.out.print(doj.get(Calendar.DATE)+"/");
		System.out.print(doj.get(Calendar.MONTH)+"/");
		System.out.println(doj.get(Calendar.YEAR));
		System.out.println("Semester: "+semester);
		System.out.println("GPA: "+gpa);
		System.out.println("CGPA: "+cgpa);
	}
	static void sort_semester(student s[]){//Works
		student temp = new student();
		for(int i=0;i<5;i++){
			for(int j=0;j<i;j++){
				if(s[i].semester<s[j].semester){
				 temp = s[i];
				 s[i]=s[j];
				 s[j]=temp;
			    }
			}
		}
	}
	static void sort_cgpa(student s[]){//Works
		student temp = new student();
		for(int i=0;i<5;i++){
			for(int j=0;j<i;j++){
			    	if(s[i].cgpa>s[j].cgpa){
					 temp = s[i];
					 s[i]=s[j];
					 s[j]=temp;
	   				}
			}
		}
	}
	static void sort_name(student s[]){//Works
		student temp = new student();
		for(int i=0;i<5;i++){
			for(int j=0;j<i;j++){
			   	if(s[i].fullname.compareTo(s[j].fullname)<0){
					 temp = s[i];
					 s[i]=s[j];
					 s[j]=temp;
	   			}
			}
		}
	}
	static void first_char(student s[], char start){//Works
		for(int i=0;i<5;i++){
			if(s[i].fullname.charAt(0) == start){
				System.out.print(s[i].fullname+"\t");
			}
		}
	}
	static void sub_string(student s[],String sub){//Works
		for(int i=0;i<5;i++){
			if(s[i].fullname.indexOf(sub,0)!=-1){
				System.out.print(s[i].fullname+"\t");
			}
		}
	}
	static void short_name(student s[]){//Works
		for(int i=0;i<5;i++){
			String sub[] = s[i].fullname.split(" ");
			s[i].fullname = "" + sub[0].charAt(0);
			for(int j=1;j<sub.length - 1 ;j++){
				s[i].fullname = s[i].fullname + " " + sub[j].charAt(0); 
			}
			s[i].fullname = s[i].fullname +" " + sub[sub.length -1 ];
		}			
	}
	//Main starts here
	public static void main(String[] args){
		Scanner scan = new Scanner(System.in);
		student s[] = new student[5];
		String regnum;
		String fullname;
		int doj[] = new int[3];
		doj[0] = 18;
		doj[1] = 7;
		doj[2] = 2017;
		short semester;
		float gpa,cgpa;
		String sub;
		char start;
		for(int i=0;i<5;i++){
			System.out.println("Enter details of student");
			System.out.print("Number: ");
			scan.nextLine();
			regnum = scan.nextLine();
			System.out.print("Name: ");
			fullname = scan.nextLine();
			System.out.print("Date of Joining(dd mm yy): ");
			doj[0] = scan.nextInt();
			doj[1] = scan.nextInt();
			doj[2] = scan.nextInt();
			System.out.print("Semester: ");
			semester  = scan.nextShort();
			System.out.print("GPA: ");
			gpa = scan.nextFloat();
			System.out.print("CGPA: ");
			cgpa = scan.nextFloat();
			s[i] = new student(regnum,fullname,doj,semester,gpa,cgpa);
		}
		//Details are assigned manually here for debugging purposes only
		/*s[0] = new student("80","Rohil Narula",doj,(short)3,10.0f,10.0f);
		s[1] = new student("75","Govind Ravindranath",doj,(short)3,8.7f,8.5f);
		s[2] = new student("69","Rakesh Sharma",doj,(short)5,9f,9.8f);
		s[3] = new student("45","Anil Vikas",doj,(short)1,0f,0f);
		s[4] = new student();*/
		//s[4].display();
		student.sort_semester(s);
		System.out.print("Students sorted by semester are:\t");
		for(int i=0;i<5;i++){
			System.out.print(s[i].semester+"\t");
		}
		System.out.println();
		student.sort_cgpa(s);
		System.out.print("Students sorted by cgpa are:\t");
		for(int i=0;i<5;i++){
			System.out.print(s[i].cgpa+"\t");
		}
		System.out.println();
		student.sort_name(s);
		System.out.print("Students sorted by Name are:\t");
		for(int i=0;i<5;i++){
			System.out.print(s[i].fullname+"\t");
		}
		System.out.println();
		System.out.print("Enter the character the students' names should start with:");
		scan.nextLine();
		fullname = scan.nextLine();
		start = fullname.charAt(0);
		System.out.print("Students whose names start with "+start+" are:\t");
		student.first_char(s,start);
		System.out.println();
		System.out.print("Enter the substring to be contained in the students' names:");
		sub = scan.nextLine();
		System.out.print("Students whose names contain "+sub+" are:\t");
		student.sub_string(s,sub);
		System.out.println();
		System.out.println("Students with their names shortened are:");
		student.short_name(s);
		for(int i=0;i<5;i++){
			System.out.println(s[i].fullname);
		}
		System.out.print("Enter the record number to be displayed:");
		int i = scan.nextInt();
		s[i-1].display();
	}
}
