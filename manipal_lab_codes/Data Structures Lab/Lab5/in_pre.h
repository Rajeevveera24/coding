#define MAX 20
typedef struct 
{
	char data[MAX];
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
void push(stack*s,char x)
{
	s->top=s->top+1;
	s->data[s->top] = x;
}
char pop(stack *s)
{
	char x;
	if(!empty(s))
	{
		x=s->data[s->top];
		s->top=s->top-1;
		return x;
	}
}
void disp(stack *s)
{
	for(int i=s->top;i>=0;i--)
	{
		printf("%c",s->data[i]);
	}
}
int is_prior(char a, char b)
{
	if(a=='^')
		return 1;
	else if(a=='%' & b!='^')
		return 1;
	else if((a =='/' || a == '*') & (b == '*' || b == '/' || b == '+' || b == '-'))
		return 1;
	else if((a == '+' || a == '-') & (b == '+' || b == '-'))
		return 1;
	else
		return 0;
}