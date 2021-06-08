#include<stdio.h>
int main()
{
     int *p;
     int i=0,a[]={10,2,4,6,7,99};
     p=a;
     printf("Array in forward direction is:\t");
     while(i<=5)
     {
          printf("%d\t",*(p));
          p++;
          i++;
     }
     printf("\n");
     i=0;
     p--;
     printf("Array in reverse direction is:\t");
     while(i<=5)
     {
          printf("%d\t",*(p));
          p--;
          i++;
     }
     printf("\n");
     return 0;
}
