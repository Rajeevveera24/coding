#include <stdio.h>

void swap(int *x, int *y){
	int temp = *x;
	*x = *y;
	*y = temp;
}
void heapify(int a[], int n, int i){
	int largest = i;
	int l = 2*i + 1;
	int r = 2*i + 2;
	if(l < n && a[largest] < a[l]){
		largest = l;
	}
	if(r <n && a[largest] < a[r]){
		largest = r;
	}
	if(largest != i){
		swap(&a[i], &a[largest]);
		heapify(a, n, largest);
	}
}

void printArray(int arr[], int n){ 
    for (int i=0; i<n; i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
} 

void heapSort(int a[], int n){
	for(int i=n/2-1; i>=0; i--){
    	heapify(a, n, i);
    }
    for(int i=n-1; i>=1; i--){
    	swap(&a[0], &a[i]);
    	printArray(a, i+1);
    	// printf("%d\n",i-1);
    	heapify(a, i, 0);
    	printArray(a, i);
    }
}

int main(){ 
    int arr[30], n;
    printf("Enter size: ");
    scanf("%d", &n);
    printf("Enter the elements: ");
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
  
    heapSort(arr, n); 
 
    printf("Sorted array is ");
    printArray(arr, n); 
} 