// namespace std have been included for this problem.
bool is_subset_sum(int a[], int size, int num, int sum, int index){
    if(sum == num){
        return true;
    }
    if(index == size){
        return false;
    }
    if(a[index] == num){
        return is_subset_sum(a, size, num, sum, index+1);
    }
    return is_subset_sum(a, size, num, sum ,index+1) || is_subset_sum(a, size, num , sum - a[index], index+1);
}
// Add any helper functions(if needed) above.
bool group_sum_with_num(int arr[], int sz, int must_have, int target_sum)
{
    return is_subset_sum(arr, sz, must_have, target_sum, 0);
}