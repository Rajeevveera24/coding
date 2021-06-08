#include<stdio.h>
#include<string.h>
int is_palindrome(char *string, int l_index, int r_index)
{
     if(l_index>=r_index)
          return 1;
     if(string[l_index]==string[r_index])
          is_palindrome(string,l_index+1,r_index-1);
     else
          return 0;
}

int main()
{
     char string[30];
     printf("Enter the string to be checked\n");
     gets(string);
     //printf("%d\n",strlen(string));
     //printf("%s\n",string);
     if(is_palindrome(string,0,strlen(string)-1))
          printf("String is a palindrome\n");
     else
          printf("String is not a palindrome\n");
     return 0;
}
