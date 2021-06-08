#define MAX 10
#define true 1
#define false 0
typedef struct 
{
	char item[MAX];
	int top;
}stack;
void push(stack *ps,char x);
char pop(stack *ps);
int empty(stack *ps);
void push(stack *ps, char x)
{
	if(ps->top!=MAX-1)
	{
		ps->top++;
		ps->item[ps->top]=x;
	}
}
char pop(stack *ps)
{
	if(!empty(ps))
	{
		return (ps->item[ps->top--]);
	}
}
void pop2(stack *ps)
{
	if(!empty(ps))
	{
		printf("%d is popped\n",(ps->item[ps->top--]));
	}
	else{
		printf("Stack empty\n");
	}
}
int empty(stack *ps)
{
	if(ps->top==-1)
	{
		return (true);
	}
	else
	{
		return (false);
	}
}