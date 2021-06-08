#define MAX 20
typedef struct 
{
	int data[MAX];
	int top;
}stack;
void init (stack *s)
{
	s->top=-1;
}
int empty(stack *s)
{
	if(s->top==-1)
		return 1;
	else
		return 0;
}
int full(stack *s)
{
	if(s->top==MAX-1)
		return 1;
	else
		return 0;
}
void push(stack*s,int x)
{
	s->top=s->top+1;
	s->data[s->top] = x;
}
int pop(stack *s)
{
	int x;
	x=s->data[s->top];
	s->top=s->top-1;
	return x;
}
int power(int x, int y)
{	
	if(y==1)
		return x;
	else
		return (x*power(x,y-1));
}
int evaluate(char x, int op1 , int op2)
{
	if(x=='+')
		return (op1+op2);
	else if(x=='-')
		return (op1-op2);
	else if(x=='*')
		return (op1*op2);
	else if(x=='/')
		return (op1/op2);
	else if(x=='^')
		return (power(op1,op2));
	else 
		return (op1%op2);
}
