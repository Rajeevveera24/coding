#include<stdio.h>
#include"Quadratic_Equation.h"

int main()
{
	int a1,b1,c1;
	float y1,y2;
	int *a=&a1,*b=&b1,*c=&c1;
	float *x1=&y1,*x2=&y2,flag;

	getdata(a,b,c);
	flag = quadratic(*a,*b,*c,x1,x2);
	if(flag==1)
		print_roots(x1,x2);
	return 0;
}