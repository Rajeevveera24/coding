// namespace std have been included for this problem.

// Add any helper functions(if needed) above.
vector<string>  get_permutations(string s) 
{
    vector<string> result1;
    if(s.length() <= 1){
        result1.push_back(s);
        return result1;
    }
    result1 = get_permutations(s.substr(1));
    vector<string> result;
    for(int i=0; i<result1.size(); i++){
        string str = result1.at(i);
        int len = str.length();
        for(int j=-1; j<len; j++){
            result.push_back(str.substr(0,j+1) + s.at(0) + str.substr(j+1));
        }
    }
    return result;
}
