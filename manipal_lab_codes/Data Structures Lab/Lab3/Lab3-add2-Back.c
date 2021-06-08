#include <stdio.h>
#include <string.h>
void  Back(char*string, int index)
{
	if(index>=0)
	{
		printf("%c",string[index]);
		Back(string,index-1);
	}
}
int main()
{
	char string[80];
	printf("Enter the string\n");
	gets(string);
	printf("The string backwards is: \t");
	Back(string,strlen(string)-1);
	printf("\n");
	return 0;
}