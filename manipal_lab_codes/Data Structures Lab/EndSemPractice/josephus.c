#include<stdio.h>
#include<stdlib.h>

int josephus_position(int  n, int k){

	int i,count;
	int *arr = (int*)calloc(n,sizeof(int));

	for(i=0;i<n;i++){
		arr[i] = i+1;
	}

	count = n;
	i = k+1;
	if(i>count){
		i = i%count;
	}
	while(count>1){
		//printf("%d\n",arr[i]);
		for(int j=i;j<count-1;j++){
			arr[j] = arr[j+1];
		}

		count--;
		i += k+1;
		if(i>=count){
			i = i%count;
		}
	}

	return arr[0];
}

int main(){
	int n,k;

	scanf("%d",&n);
	scanf("%d",&k);
	printf("%d\n",josephus_position(n,k));
	return 0;
}