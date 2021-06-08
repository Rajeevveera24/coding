#include <stdio.h> 
#include <stdlib.h>

void swap(int *, int *);
void printArray(int arr[], int);
int partition(int *, int, int);
void quickSort(int *, int, int);

int opCount = 0;
int main(){ 
    int *arr, n;

    printf("Enter the size of the array: ");
    scanf("%d",&n);
    
    arr = (int*)malloc(n*sizeof(int));

    printf("Enter the elements of the array: ");
    for(int i=0; i<n; i++){
        scanf("%d",&arr[i]);
    }

    quickSort(arr, 0, n-1); 
    
    printf("Sorted array: "); 
    printArray(arr, n);

    printf("Operation count is %d\n",opCount);

    return 0; 
}

void swap(int* a, int* b) { 
    int t = *a; 
    *a = *b; 
    *b = t; 
} 

void printArray(int arr[], int size){  
    for (int i=0; i<size; i++){ 
        printf("%d ", arr[i]);
    }
    printf("\n"); 
} 

int partition (int arr[], int low, int high){ 
    int pivot = arr[low];
    int i = low;
    int j = high+1;
    do{
        do{
            i++;
        }while(arr[i] < pivot);
        do{
            j--;
        }while(arr[j] > pivot);
        swap(&arr[i], &arr[j]);
    }while(i<j);
    swap(&arr[i], &arr[j]);
    swap(&arr[j], &arr[low]);
    return j; 
} 

void quickSort(int arr[], int low, int high){ 
    if (low < high){ 
        int pi = partition(arr, low, high); 
        quickSort(arr, low, pi - 1); 
        quickSort(arr, pi + 1, high);
    } 
} 