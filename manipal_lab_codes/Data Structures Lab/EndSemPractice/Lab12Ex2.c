#include <stdio.h>

int main(){
	int *arr,size,j,small;
	printf("Enter size: ");
	scanf("%d",&size);
	printf("Enter the elements: ");
	for(int i=0;i<size;i++){
		scanf("%d",(arr+i));
	}
	for(int i=1;i<size;i++){
		small = arr[i];
		j = i-1;
		while(small<arr[j] && j>=0){
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = small;
	}
	printf("Sorted array is:\t");
	for(int i = 0;i<size;i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
	return 0;
}