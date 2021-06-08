#include <stdio.h>

void swap(int *a, int *b){
    *a += *b;
    *b = *a - *b;
    *a -= *b;
}

void heapify(int arr[], int n, int i){ 
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;
   
    if (l < n && arr[l] > arr[largest]){ 
        largest = l;
    }  
    if (r < n && arr[r] > arr[largest]){
        largest = r; 
    }
  
    if (largest != i){
        {
            arr[i] += arr[largest];
            arr[largest] = arr[i] - arr[largest];
            arr[i] -= arr[largest];
        }
        heapify(arr, n, largest); 
    } 
} 

void heapSort(int *arr, int n){  
    for (int i = n/2 - 1; i >= 0; i--){ 
        heapify(arr, n, i);
    }
  
    for (int i=n-1; i>=1; i--){
        {
            arr[i] += arr[0];
            arr[0] = arr[i] - arr[0];
            arr[i] -= arr[0];
        }
        heapify(arr, i-1, 0);
    } 
} 

void printArray(int arr[], int n){ 
    for (int i=0; i<n; i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
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
    //heapify(arr, n, n/2);
    printf("Sorted array is ");
    printArray(arr, n); 
} 