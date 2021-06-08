#include<stdio.h>
#include<stdlib.h>
#include "stack_operations.h"
void main()
{
	char expn[25],c,d;
	int i=0;
	stack s;
	s.top=-1;
	printf("Enter the Expression\n");
	gets(expn);
	while((c=expn[i++])!='\0')
	{
		if(c=='(')
		{
			push(&s,c);
		}
		else
		{
			if(c==')')
			{
				d=pop(&s);
				if(d!='(')
				{
					printf("Invalid Expression\n");
					exit(0);
				}
			}
		}
	}
	if(empty(&s))
	{
		printf("Balanced Expression\n");
	}
	else
	{
		printf("Not a Balanced Expression\n");
	}
}