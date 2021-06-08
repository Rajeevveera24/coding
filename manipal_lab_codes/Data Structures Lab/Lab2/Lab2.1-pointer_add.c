#include<stdio.h>
void sum(int *p1, int *p2, int *p3)
{
	*p3 = *p1 + *p2;
}
int main()
{
	int num1,num2,num3;
	int *p1=&num1,*p2=&num2,*p3=&num3;
	printf("Enter two numbers\n");
	scanf("%d",p1);
	scanf("%d",p2);
	sum(p1,p2,p3);
	printf("Sum is %d\n",*p3);
	return 0;
}
