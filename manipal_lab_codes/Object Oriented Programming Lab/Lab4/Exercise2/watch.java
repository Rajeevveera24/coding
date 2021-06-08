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
			System.out.println(t.hour+":"+"0"+t.min+":"+t.sec);
		else if((t.hour>=10) & (t.min>=10) & (t.sec<10))//110
			System.out.println(t.hour+":"+"0"+t.min+":"+"0"+t.sec);
		else//111
			System.out.println(t.hour+":"+"0"+t.min+":"+"0"+t.sec);
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
		Scanner scan = new Scanner(System.in);
		System.out.println("Enter the time in hours, time and minutes");
		t1.hour = scan.nextInt();
		t1.min = scan.nextInt();
		t1.sec = scan.nextInt();
		t1=Time.check(t1);
		System.out.print("The default time is ");
		Time.display(t2);
		System.out.print("The parametrized time is ");
		Time.display(t1);
	}
}