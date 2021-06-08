#include <stdio.h>
#include <stdlib.h>

int fact(int n);
int digitSum(int n);
int isStrong(int n);

int main(){
	int *arr, size;
	//printf("%d\n",digitSum(28)); 

	printf("Enter size of the array:\t");
	scanf("%d",&size);

	arr = (int*)malloc(size*sizeof(int));

	printf("Enter the elements of array:\t");

	for(int i=0;i<size;i++){
		scanf("%d",&arr[i]);
	}

	printf("\nRemoving the strong numbers...\n\n");

	for(int i=0;i<size;i++){
		if(isStrong(arr[i])){
			size--;
			//printf("%d",arr[i]);
			for(int j=i; j<size;j++){
				arr[j] = arr[j+1];
			}
			//printf("%d ",i);
			i--;
		}
	}

	printf("Array after the removal of strong numbers is:\t");

	for(int i=0;i<size;i++){
		printf("%d ",arr[i]);
	}

	printf("\n\nGoodbye...\n\n");

	return 0;
}

int fact(int n){
	if(n == 0 || n == 1){
		return 1;
	}
	return (n *fact(n-1)); 
}

int digitSum(int num){
	if(num < 10){
		return num;
	}
	return (num%10) + digitSum(num/10);
}
int isStrong(int num){
	int fct = fact(num);
	int sum = digitSum(fct);
	return (num == sum);
}