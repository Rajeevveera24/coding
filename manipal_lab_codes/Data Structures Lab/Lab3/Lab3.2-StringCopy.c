#include<stdio.h>
#include<string.h>

void copy_string(char*string1, char*string2, int i1, int i2, int size)
{
	if(i1<size)
		{
			string2[i2]=string1[i1];
			string2[i2+1]='\0';
			copy_string(string1,string2,i1+1,i2+1,size);
		}
}
int main()
{
	char string1[30], string2[30];
	printf("Enter the string to be copied\n");
	scanf("%s",string1);
	copy_string(string1,string2,0,0,strlen(string1));
	printf("The copied string is %s\n",string2);
	return 0;
}