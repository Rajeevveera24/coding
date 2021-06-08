#include<stdio.h>
#include"array_secondlargest.h"
int main()
{
	int arr[20],seclarg,size;
	printf("Enter size of array\n");
	scanf("%d",&size);
	printf("Enter elements of array\n");
	for(int i=0;i<size;i++)
	{
		scanf("%d",&arr[i]);
	}
	seclarg=SecondLargest(arr,size);
	printf("Second largest element in the array is ");
	printf("%d",seclarg);
	printf("\n");
	return 0;
}