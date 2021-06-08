#include<math.h>

void getdata(int *a, int *b, int *c)
{
	printf("Enter the values of coefficients\n");
	scanf("%d",a);
	scanf("%d",b);
	scanf("%d",c);
}
int quadratic(int a, int b, int c, float *x1, float *x2)
{
	float d;
	d = b*b - 4*a*c;
	if(d<0)
		{
			printf("Roots are Imaginary\n");
			return 0;
		}	
	else
	{
		*x1 = (-b + sqrt(d)) / (a*2);
		*x2 = (-b - sqrt(d)) / (a*2);
		return 1;
	}
}
void print_roots(float *x1, float *x2)
{
	printf("Roots are %f and %f \n",*x1,*x2);
}