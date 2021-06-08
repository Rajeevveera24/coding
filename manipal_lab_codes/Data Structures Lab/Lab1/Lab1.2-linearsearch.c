#include<stdio.h>
#include"array_linearsearch.h"
int main()
{
	int arr[20],num,size;
	printf("Enter the size of the array\n");
	scanf("%d",&size);
	printf("Enter the elements\n");
	for(int i=0;i<size;i++)
	{
		scanf("%d",&arr[i]);
	}
	printf("Enter the number to be found\n");
	scanf("%d",&num);
	Linsearch(arr,size,num);
	return 0;
}