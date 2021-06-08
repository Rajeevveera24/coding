int SecondLargest(int arr[], int size)
{
	int i,larg,seclarg;
	larg=arr[0];
	seclarg=arr[0];

	for(i=1;i<size;i++)
	{
		if(arr[i]>larg)
		{
			seclarg=larg;
			larg=arr[i];
		}
	}
	return seclarg;
}