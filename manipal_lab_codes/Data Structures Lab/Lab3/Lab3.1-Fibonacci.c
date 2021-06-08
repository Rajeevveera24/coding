#include<stdio.h>
int fibo(int n)
{
     if(n==0||n==1)
          return n;
     else
          return (fibo(n-1)+fibo(n-2));
}
int main()
{
     int num,i;
     printf("Enter the number of Fibonacci numbers to be generated\n");
     scanf("%d",&num);
     printf("The first %d Fibonacci numbers are:\t",num);
     for(i=0;i<num;i++)
     {
          printf("%d\t",fibo(i));
     }
     printf("\n");
     return 0;
}
