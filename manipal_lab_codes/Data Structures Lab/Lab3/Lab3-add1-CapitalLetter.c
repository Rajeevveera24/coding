#include<stdio.h>
#include<string.h>
int flag=0;
void Capital_letter(char *string, int index, int size)
{
	if(index<size)
	{
		if(string[index] >= 65 && string[index]<=90)
			{
				printf("First Capital letter is %c found in %d position\n",string[index],index+1);
				flag=1;
			}
		else
			Capital_letter(string,index+1,size);
	}
}
int main()
{
	char string[30];
	printf("Enter the string\n");
	gets(string);
	Capital_letter(string,0,strlen(string));
	if(flag==0)
		printf("No Capital letter found in the string\n");
	return 0;
}