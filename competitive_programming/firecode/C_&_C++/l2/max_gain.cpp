// Given an array of integers, write a method - max_gain - that returns the maximum gain. 
// Maximum Gain is defined as the maximum difference between 2 elements in a list such that 
// the larger element appears after the smaller element. If no gain is possible, return 0.


// namespace std have been included for this problem.

// Add any helper functions(if needed) above.
int max_gain(int arr[], int sz)
{
    int min = arr[0], max_diff = 0;
    
    for(int i=1; i<sz; i++){
        if((arr[i] - min)> max_diff){
            max_diff = arr[i];
        }
        if(arr[i] < min){
            min = arr[i];
        }
    }
    return max_diff;

}