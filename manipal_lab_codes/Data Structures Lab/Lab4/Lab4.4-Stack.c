#include<stdio.h>
#define N 30
void del(int arr[N], int pos , int size, int *j);
int main(){
	int i,j=1,k,n,arr[N];
	printf("Enter the values of n and k\n");
	scanf("%d",&n);
	scanf("%d",&k);
	printf("Enter the elements of the array\n");
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	while(j<=k){
		for(i=0;i<n-j,j<=k;i++){
			if(arr[i]<arr[i+1]){
				del(arr,i,n,&j);
				break;
			}
		}
	}
	printf("Elements of the modified array are:\t");
	for (i = 0; i < n-k; i++){
		printf("%d\t",arr[i]);
	}
	printf("\n");
	return 0;
}
void del(int arr[N], int pos , int size, int *j){
	int i=pos;
	for(i=pos;i<size-*j;i++){
		arr[i]=arr[i+1];
	}
	(*j)++;
}