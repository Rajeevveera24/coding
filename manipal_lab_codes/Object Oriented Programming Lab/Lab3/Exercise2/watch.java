import java.util.Scanner;

class Time
{
	int hour,min,sec;
	Time()
	{
		hour=0;
		min=0;
		sec=0;
	}
	Time(int hour,int min,int sec)
	{
		this.hour=hour;
		this.min=min;
		this.sec=sec;
	}
	public static void display(Time t)
	{
		if((t.hour<10) & (t.min<10) & (t.sec<10))//000
			System.out.println("0"+t.hour+":"+"0"+t.min+":"+"0"+t.sec);
		else if((t.hour<10) & (t.min<10) & (t.sec>=10))//001
			System.out.println("0"+t.hour+":"+"0"+t.min+":"+t.sec);
		else if((t.hour<10) & (t.min>=10) & (t.sec<10))//010
			System.out.println("0"+t.hour+":"+t.min+":"+"0"+t.sec);
		else if((t.hour<10) & (t.min>=10) & (t.sec>=10))//011
			System.out.println("0"+t.hour+":"+t.min+":"+t.sec);
		else if((t.hour>=10) & (t.min<10) & (t.sec<10))//100
			System.out.println(t.hour+":"+"0"+t.min+":"+"0"+t.sec);
		else if((t.hour>=10) & (t.min<10) & (t.sec>=10))//101
			System.out.println(t.hour+":0"+t.min+":"+t.sec);
		else if((t.hour>=10) & (t.min>=10) & (t.sec<10))//110
			System.out.println(t.hour+":"+t.min+":0"+t.sec);
		else//111
			System.out.println(t.hour+":"+t.min+":"+t.sec);
	}
	public static Time add(Time t1, Time t2)
	{
		Time t3 = new Time();
		t3.hour= t1.hour+t2.hour;
		t3.min = t1.min + t2.min;
		t3.sec = t1.sec + t2.sec;
		Time.check(t3);
		return t3;
	}
	public static Time sub(Time t1, Time t2)
	{
		Time t3 = new Time();
		t3.hour= t1.hour-t2.hour;
		t3.min = t1.min - t2.min;
		t3.sec = t1.sec - t2.sec;
		Time.check(t3);
		return t3;
	}
	public static void compare(Time t1, Time t2)
	{
		if(t1.hour == t2.hour)
		{
			if(t2.min == t1.min)
			{
				if(t1.sec==t2.sec)
				{
					System.out.println("Two times are equal");
				}
				else if(t1.sec>t2.sec)
				{
					System.out.println("First time is greater");
				}
				else
				{
					System.out.println("First time is smaller");
				}
			}
			else if(t1.min>t2.min)
			{
				System.out.println("The first time is greater");
			}
			else
			{
				System.out.println("The first time is smaller");
			}
		}
		else if (t1.hour>t2.hour)
		{
			System.out.println("The first time is greater");
		}
		else
		{
			System.out.println("The first time is smaller");
		}
	}
	public static Time check(Time t)
	{
		while(t.hour>=24 || t.min >=60 || t.sec>=60 || t.hour<0 || t.min<0 || t.sec<0)
		{
			if(t.hour>=24)
				t.hour-=24;
			if(t.min>=60)
			{
				t.min-=60;
				t.hour+=1;
			}
			if(t.sec>=60)
			{
				t.sec-=60;
				t.min+=1;
			}
			if(t.hour<0)
				t.hour+=24;
			if(t.min<0)
			{
				t.hour-=1;
				t.min+=60;
			}
			if(t.sec<0)
			{
				t.sec+=60;
				t.min-=1;
			}
		}
		return t;
	}
}
class watch
{
	public static void main(String[] args)
	{
		Time t1 = new Time();
		Time t2 = new Time();
		int option=1;
		Scanner scan = new Scanner(System.in);
		System.out.println("Enter the first time in hours, time and minutes");
		t1.hour = scan.nextInt();
		t1.min = scan.nextInt();
		t1.sec = scan.nextInt();
		t1=Time.check(t1);
		System.out.print("The first time is ");
		Time.display(t1);
		System.out.println("Enter the second time in hours, time and minutes");
		t2.hour = scan.nextInt();
		t2.min = scan.nextInt();
		t2.sec = scan.nextInt();
		t2=Time.check(t2);
		System.out.print("The second time is ");
		Time.display(t2);
		while(option!=0)
		{
			System.out.println("Enter 1 to add, 2 to subtract and 3 to compare the 2 times. Enter 0 to exit");
			option=scan.nextInt();
			if (option==1)
			{
				Time t3=new Time();
				t3 = Time.add(t1,t2);
				System.out.print("Addition of the two time is ");
				Time.display(t3);
			}
			else if (option==2)
			{
				Time t3=new Time();
				t3 = Time.sub(t1,t2);
				System.out.print("subtraction of the two time is ");
				Time.display(t3);
			}
			else if (option==3)
			{
				Time.compare(t1,t2);
			}
			else
			{
				break;
			}
		}
	}
}
