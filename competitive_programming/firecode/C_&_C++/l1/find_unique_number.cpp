// Find the Number that Appears Once 

// namespace std have been included for this problem.

// Add any helper functions(if needed) above.
int single_number(int arr[], int sz)
{
    map <int, int> hmp;
    map <int, int>::iterator itr;
    
    for(int i=0; i<sz; i++){
        itr = hmp.find(arr[i]);
        
        if(itr != hmp.end()){
            itr->second += 1;
        }
        else{
            hmp.insert(pair<int, int>(arr[i], 1));
        }
    }
    
    for(int i=0; i<sz; i++){
        itr = hmp.find(arr[i]);
        
        if(itr->second == 1){
            return arr[i];
        }
    }
    return 0;
}