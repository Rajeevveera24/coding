#include <stdio.h>
#include <stdlib.h>
void counting_sort(int A[],int n)
{
	int i,j;
	int S[15],C[100];
    for(i=0;i<=n-1;i++)
      C[i]=0;
    for(i=0;i<=n-2;i++)
    {
    	for(j=i+1;j<=n-1;j++)
    	{
    		if(A[i]<A[j])
    		   C[j]=C[j]+1;
    	    else
    	    	C[i]=C[i]+1;
    	}
    }
    for(i=0;i<=n-1;i++)
    	S[C[i]]=A[i];
    printf("\nSorted Array is ");
    for(i=0;i<=n-1;i++)
    	printf("%d ",S[i]);
}
int main()
{
	int n,k=0,a[15],i;
	printf("Enter limit");
	scanf("%d",&n);
	printf("Enter elements");
    for(i=0;i<n;i++)
    	scanf("%d",&a[i]);
    counting_sort(a,n);
}