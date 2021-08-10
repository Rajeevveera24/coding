int find_missing_number(int arr[], int n) {
    
    int sum = 0;
    int total = n+1;
    for (int i= 0;i<n;i++){
      sum = arr[i]^sum;       /* XOR of all the elements of the array */ 
      total = total^(i+1);    /* XOR of all the numbers from 1 to n+1 */ 
    }
    /* XOR of sum and total gives the missing number.*/
    return sum^total;   
}