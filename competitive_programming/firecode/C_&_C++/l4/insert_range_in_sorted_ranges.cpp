//Insert a given range into a set of sorted ranges and return a sorted set of ranges


// namespace std have been included for this problem.

// Add any helper functions(if needed) above.
vector<Interval> insert_range(vector<Interval> intervals_list, Interval insert) 
{
    vector <Interval> result;
    Interval prev;
    for(int i=0; i<intervals_list.size(); i++){
        prev = intervals_list.at(i);
        
        if (prev.end < insert.start){
            result.push_back(prev);
        }
        else if(prev.start > insert.end){
            result.push_back(insert);
            insert = prev;
        }
        else{
            int start = min(prev.start, insert.start);
            int end = max(prev.end, insert.end);
            insert =  Interval(start, end);
        }
    }
    result.push_back(insert);
    return result;
}