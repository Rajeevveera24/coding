// #include<algorithm>
// namespace std have been included for this problem.
bool compare(Interval i1, Interval i2){
    return (i1.start < i2.start);
}
// Add any helper functions(if needed) above.
vector<Interval> merge_intervals(vector<Interval> intervals_list)
{
    if(intervals_list.size() < 2){
        return intervals_list;
    }
    else{
        vector<Interval> result;
        
        std::sort(intervals_list.begin(), intervals_list.end(), compare);
        
        Interval prev = intervals_list.at(0);
        
        for(int i=0; i<intervals_list.size(); i++){
            Interval cur = intervals_list.at(i);
            if(prev.end >= cur.start){
                prev.end = max(prev.end, cur.end);
            }
            else{
                result.push_back(prev);
                prev = cur;
            }
        }
        result.push_back(prev);
        return result;
    }
}