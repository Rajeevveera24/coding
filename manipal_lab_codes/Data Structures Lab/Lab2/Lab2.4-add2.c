#include<stdio.h>
struct complexnumber
{
	int real,complex;
}
void add(complexnumber num1, complexnumber num2, complexnumber sum)
{
	sum.real = num1.real+num2.real;
	sum.complex = num1.complex+num2.complex;
}
void subtract(complexnumber num1, complexnumber num2, complexnumber sub)
{
	sub.real = num1.real-num2.real;
	sub.complex = num1.complex-num2.complex;	
}
void input(complexnumber num)
{
	printf("Enter real part");
	scanf("%d",num.real);
	printf("Enter Complex part");
	scanf("%d",num.complex);
}
void output(complexnumber num)
{
	printf("Number is %d + %di\n",num.real,num.complex);
}
int main()
{
	complexnumber num1,num2,sum,sub;
	input(num1);
	output(num1);
	input(num2);
	output(num2);
	add(num1,num2,sum);
	output(sum);
	subtract(num1,num2,sub);
	output(num);
	return 0;
}