#include <stdio.h>
#include <stdlib.h>

int opCount = 0;

void merge(int arr[], int, int, int);
void mergeSort(int arr[], int, int);
void printArray(int arr[], int);

int main(){
    int *arr, n;

    printf("Enter the size of the array: ");
    scanf("%d",&n);
    
    arr = (int*)malloc(n*sizeof(int));
    
    printf("Enter the elements of the array: ");
    for(int i=0; i<n; i++){
        scanf("%d",arr+i);
    } 
  
    mergeSort(arr, 0, n-1); 

    printf("Sorted array: "); 
    printArray(arr, n);

    printf("Operation count is %d\n",opCount);

    return 0; 
}

void merge(int arr[], int l, int m, int r){ 
    int i, j, k = l; 
    int n1 = m - l + 1; 
    int n2 =  r - m; 

    int L[n1], R[n2]; 

    for(i=0; i<n1; i++){ 
        L[i] = arr[l + i];
    }

    for(j=0; j<n2; j++){ 
        R[j] = arr[m + 1+ j]; 
    }
    i = j = 0;
    while (i<n1 && j<n2){
        opCount++; 
        if(L[i] <= R[j]){ 
            arr[k] = L[i]; 
            i++; 
        } 
        else{ 
            arr[k] = R[j]; 
            j++; 
        }

        k++; 
    }

    while (i < n1){
        opCount++;
        arr[k] = L[i]; 
        i++; 
        k++; 
    }

    while (j < n2){
        opCount++;
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
}

void mergeSort(int arr[], int l, int r){ 
    if (l<r){ 
        int m = l+(r-l)/2; 

        mergeSort(arr, l, m); 
        mergeSort(arr, m+1, r); 
        merge(arr, l, m, r); 
    }
}

void printArray(int A[], int size){ 
    int i; 
    for (i=0; i < size; i++){
        printf("%d ", A[i]); 
    }
    printf("\n"); 
} 