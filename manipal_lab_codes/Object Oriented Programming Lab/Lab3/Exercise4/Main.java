/* Java program to implement basic stack
operations */
class Stack
{
	static final int MAX = 1000;
	int top;
	int a[] = new int[MAX]; // Maximum size of Stack
	boolean isEmpty()
	{
		return (top < 0);		
	}
	Stack()
	{
		top=-1;
	}
	boolean push(int x)
	{
		if (top >= (MAX-1))
		{
			System.out.println("Stack Overflow");
			return false;
		}
		else
		{
			a[++top] = x;
			return true;
		}
	}
	int pop()
	{
		if (top < 0)
		{
			System.out.println("Stack Underflow");
			return 0;
		}
		else
		{
			int x = a[top--];
			return x;
		}
	}
	void display()
	{
		for(int i=top;i>=0;i--)
		{
			System.out.println(a[i]);
		}
	}
}
	// Driver code
class Main
{
	public static void main(String args[])
	{
		Stack s = new Stack();
		s.push(10);
		s.push(20);
		s.push(30);
		s.display();
	}
}