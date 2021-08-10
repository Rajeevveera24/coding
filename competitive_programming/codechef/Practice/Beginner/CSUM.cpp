#include <iostream>

using namespace std;

#include <stdio.h> 
#include <stdlib.h>

void swap(int *, int *);
void printArray(int arr[], int);
int partition(int *, int, int);
void quickSort(int *, int, int);

int main() {
	int t, n, k, a[10000];
	cin>>t;
	while(t--){
	    cin>>n>>k;
	    for(int i=0; i<n; i++){
	        cin>>a[i];
	    }

	    quickSort(a, 0, n-1);

	    int flag = 0;
	    l = 0; u = n-1;
	    while(l<u){
	    	if((a[l] + a[u]) < k){
	    		l++;
	    	}
	    	else if((a[l] + a[u]) > k){
	    		u--;
	    	}
	    	else{
	    		flag = 1;
	    		break;
	    	}
	    }
	    (flag == 1 )?cout<<"Yes\n":cout<<"No\n";
	}
	return 0;
}

void swap(int* a, int* b){ 
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