#include<stdio.h>
void exchange(int *num1, int *num2)
{
	*num1 += *num2;
	*num2  = *num1 - *num2;
	*num1 = *num1 - *num2;
}
int* add(int *num1,int *num2)
{
	int a;
	int *p=&a;
	*p = *num1 + *num2;
	return p;
}
int main()
{
	int a,b;
	int *p1=&a,*p2=&b;
	int **p3=&p1, **p4=&p2;
	printf("Enter two numbers\n");
	scanf("%d%d",p1,p2);
	printf("Values are %d and %d\n",**p3,**p4);
	exchange(p1,p2);
	printf("Exchanged values are %d and %d\n",**p3,**p4);
	p1=add(p1,p2);
	printf("Sum is %d\n",*p1);
	return 0;
}