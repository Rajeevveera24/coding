void Linsearch(int arr[],int size, int num)
{
	int i,flag=0;
	for(i=0;i<size;i++)
	{
		if(arr[i]==num)
		{
			flag=1;
			break;
		}
	}
	if(flag==1)
	{
		printf("Number found in ");
		printf("%d",i+1);
		printf(" position\n");
	}
	else
		printf("Number not found in array\n");
}
