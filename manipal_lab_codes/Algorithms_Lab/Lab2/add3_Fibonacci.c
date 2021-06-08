#include <stdio.h>
int fibo(int n)
{
     if(n==0||n==1)
          return n;
     else
          return (fibo(n-1)+fibo(n-2));
}
int main()
{
     int n;
     printf("Enter the value of n:\t");
     scanf("%d",&n);
     printf("The %dth Fibonacci number is %d\n",n,fibo(n));
     return 0;
}
