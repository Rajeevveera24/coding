#include <stdio.h>
#include <stdlib.h>
int a[20]={7,0,1,2,0,3,0,4,2,3,0,3,2,1,2,0,1,7,0,1};
int p[3]={-1,-1,-1};
int use[3]={0,0,0};
int Clear()
{
	for(int i=0;i<3;i++)
		p[i]=-1;
}
int Present(int k)
{
	int i;
	for(i=0;i<3;i++)
	{
		if(p[i]==k)
			return 1;
	}
	return 0;
}
void Fifo()
{
	int i,j,k=0,h=0,m=0;
	for(i=0;i<20;i++)
	{
	   if(Present(a[i]))
	     h++;
	    else
	    {
	    	m++;
	    	p[k]=a[i];
	    	k++;
	    	if(k>=3)
	    		k=0;
	       for(j=0;j<3;j++)
	       	printf(" %d",p[j]);
	       printf("\n");
	    }  
	}
	printf("Hit:%d,Miss:%d\n",h,m);
}
int maxDist(int index)
{
  int i,j,res=-1,far=index;
  for(i=0;i<3;i++)
  {
    for(j=index;j<20;j++)
    {
    	if(p[i]==a[j])
    	{
    		if(j>far)
    		{
    			far=j;
    			res=i;
    		}
    		break;
    	}
    }
    if(j==20)
    	return i;
  }
  if(res==-1)
  	return 0;
  else
  	return res;
}
void Optimal()
{
	int i,j,k=0,t=0,h=0,m=0;
	for(i=0;i<20;i++)
	{
	   if(Present(a[i]))
	     h++;
	    else
	    {
	    	m++;
	    	k=maxDist(i+1);
	    	p[k]=a[i];	
	       for(j=0;j<3;j++)
	       	printf(" %d",p[j]);
	       printf("\n");
	    }  
	}
	printf("Hit:%d,Miss:%d\n",h,m);
}
int maxUse()
{
	int max=-1,i,u;
	for(i=0;i<3;i++)
	{
		if(max<use[i])
		{
			max=use[i];
			u=i;
		}
	}
  return u;
}
int hit(int k)
{
	int i;
	for(i=0;i<3;i++)
	{
		if(p[i]==k)
			return i;
	}
}
void Lru()
{
	int i,j,k=0,h=0,m=0;
	for(i=0;i<20;i++)
	{
		for(j=0;j<3;j++)
			use[j]++;
	   if(Present(a[i]))
	   {
	     h++;
	     use[hit(a[i])]=0;
	   }
	    else
	    {
	    	m++;
	    	p[maxUse()]=a[i];
	    	use[maxUse()]=0;
	       for(j=0;j<3;j++)
	       	printf(" %d",p[j]);
	       printf("\n");
	    }  
	}
	printf("Hit:%d,Miss:%d\n",h,m);
}
int main()
{
	printf("FIFO\n");
	Fifo();
	Clear();
	printf("\n Optimal\n");
	Optimal();
	Clear();
	printf("\n LRU\n");
	Lru();
}