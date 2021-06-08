#include <stdio.h> 
#include <string.h> 

int size = 3;
/* Function to swap values at two pointers */
void swap(int *x, int *y) 
{ 
    int temp; 
    temp = *x; 
    *x = *y; 
    *y = temp; 
} 
  
/* Function to print permutations of string 
   This function takes three parameters: 
   1. String 
   2. Starting index of the string 
   3. Ending index of the string. */
void permute(int *a, int l, int r) 
{ 
   int i; 
   if (l == r){
      for(int j=0; j<size; j++){ 
        printf("%d ", a[j]);
      }
      printf("\n");
    } 
   else
   { 
       for (i = l; i <= r; i++) 
       { 
          swap((a+l), (a+i)); 
          permute(a, l+1, r); 
          swap((a+l), (a+i)); //backtrack 
       } 
   } 
} 
  
/* Driver program to test above functions */
int main() 
{ 
    int a[3];
    a[0] = 0;
    a[1] = 1;
    a[2] = 2;
    permute(a, 0, 2); 
    return 0; 
}