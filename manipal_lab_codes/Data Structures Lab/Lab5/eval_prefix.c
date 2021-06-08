#include <stdio.h>
#include"eval_prefix.h"
#include<ctype.h>
#include<string.h>
int main()
{
	stack s;
	char x[30];
	int op1,op2,val,i;
	init(&s);
	printf("Enter the expression\n");
	gets(x);
	for(i=strlen(x)-1;i>=0;i--)
	{
		if(isdigit(x[i]))
			push(&s,x[i]-'0');
		else
		{
			op1=pop(&s);
			op2=pop(&s);
			val = evaluate(x[i],op1,op2);
			push(&s,val);
		}
	}
	val = pop(&s);
	printf("Value of the expression = %d\n",val);
	return 0;
}