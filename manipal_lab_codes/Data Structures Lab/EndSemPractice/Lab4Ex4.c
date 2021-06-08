#include<stdio.h>
#include<stdlib.h>

int main(){
	int *arr,size,k,count;
	printf("Enter the size of the array\n");
	scanf("%d",&size);
	arr = (int *)calloc(size,sizeof(int));

	printf("Enter the elements of the array\n");
	for(int i=0;i<size;i++){
		scanf("%d",arr+i);
	}
	printf("Enter the value of k\n");
	scanf("%d",&k);
	count = 0;
	while(count<k){
		for(int i=0;i<size-count-1;i++){
			if(arr[i]<arr[i+1]){
				for(int j=i;j<size-count-1;j++){
					arr[j] = arr[j+1];
				}
				break;
			}
		}
		count++;
	}
	for(int i=0;i<size-k;i++){
		printf("%d  ",arr[i]);
	}
	return 0;
}