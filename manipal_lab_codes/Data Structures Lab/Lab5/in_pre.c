#include <stdio.h>
#include"in_pre.h"
#include<ctype.h>
#include<string.h>
int main()
{
	stack exp,op;
	char x[30],temp;
	printf("Enter the expression\n");
	gets(x);
	for(int i=strlen(x)-1;i>=0;i--)
	{
		if(x[i]==')')
			push(&op,x[i]);
		else if((x[i]>=65 & x[i]<=90) || (x[i]>=97 & x[i]<=122))
			push(&exp,x[i]);
		else if(x[i]=='(')
		{
			temp='!';
			while(temp!=')')
			{
				temp = pop(&op);
				if(temp==')')
					break;
				else
					push(&exp,temp);
			}
		}
		else
		{
			if(is_prior(op.data[op.top],x[i]))
			{
				temp = pop(&op);
				push(&exp,temp);
			}
			push(&op,x[i]);
		}		
	}
	printf("Expression in prefix form is \t");
	disp(&exp);
	printf("\n");
	return 0;
}