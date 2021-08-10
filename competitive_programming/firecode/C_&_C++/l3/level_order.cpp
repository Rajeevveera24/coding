// namespace std have been included for this problem.

// Add any helper functions(if needed) above.
vector<int> level_order(treeNode* root)
{
    vector<int> list;
    
    if(!root){
        return list;
    }
    
    queue<treeNode*> q;
    
    treeNode *tmp = root;
    
    q.push(tmp);
    
    while(!q.empty()){
        
        tmp = q.front();
        q.pop();
        
        list.push_back(tmp->value);
        
        if(tmp->left){
            q.push(tmp->left);
        }
        if(tmp->right){
            q.push(tmp->right);
        }
    }
    return list;
}