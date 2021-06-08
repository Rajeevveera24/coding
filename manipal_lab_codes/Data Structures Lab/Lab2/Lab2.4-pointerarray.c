#include<stdio.h>
int main()
{
	int array[]={345,5,2,8,79};
	int *p = array;
	printf("Array in the forward direction:\t");
	while(p<array+5)
		printf(" %d",*(p++));
	printf("\n");
	p--;
	printf("Array in the reverse direction:\t");
	while(p>=array)
		printf(" %d",*(p--));
	printf("\n");
	return 0;
}