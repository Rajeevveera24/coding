#include<stdio.h>
#include"array_sum.h"
int main()
{
	int arr[20],size,arrsum;
	printf("Enter the size of the array\n");
	scanf("%d",&size);
	printf("Enter the elements\n");
	for(int i=0;i<size;i++)
	{
		scanf("%d",&arr[i]);
	}
	arrsum = Sum(arr,size);
	printf("Sum of elements of array is ");
	printf("%d",arrsum);
	printf("\n");
}