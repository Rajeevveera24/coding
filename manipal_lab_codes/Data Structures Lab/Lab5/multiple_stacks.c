#define MemorySize 10
#define MaxStack 2
int n = MaxStack;
int arr[n];
int top[MaxStack];
int bound[MaxStack];
top[0]=-1;
boundary[0]=-1;
for(int j=1;j<n;j++)
{
	top[j] = boundary[j] = (MemorySize/n)*j-1;
}
void push(int i, int x)
{
	if(top[i]==boundary[i+1])
	{
		printf("Stack Full\n");
		return;
	}
	else
	{
		arr[++top[i]]=x;
	}
}
int pop(int i)
{
	if(top[i]==boundary[i])
	{
		printf("Stack Empty\n");
		return;
	}
	else
	{
		return arr[top[i]--];
	}
}
void display(int i)
{
	int j;
	for(j=boundary[i]+1;j<=top[i];j++)
	{
		printf("%d\t",arr[j]);
	}
	printf("\n");
}
int main()
{

}
