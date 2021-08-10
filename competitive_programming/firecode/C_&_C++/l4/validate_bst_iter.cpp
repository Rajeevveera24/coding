/ namespace std have been included for this problem.
class TreeBoundaryNode{
    
    public:
        treeNode* node;
        int min, max;
        TreeBoundaryNode(treeNode* node, int min, int max){
            this->node = node;
            this->min = min;
            this->max = max;
        }
};
// Add any helper functions(if needed) above.
bool validate_bst_itr(treeNode* root)
{
    if(!root || (!root->left && !root->right)){
        return true;
    }
    queue<TreeBoundaryNode*> q;
    treeNode* tmp = root;
    TreeBoundaryNode *tmpNode = new TreeBoundaryNode(tmp, INT_MIN, INT_MAX);
    
    q.push(tmpNode);
    
    while(!q.empty()){
        tmpNode = q.front();
        q.pop();
        tmp = tmpNode->node;
        if(tmp->value < tmpNode->max && tmp->value > tmpNode->min){
            if(tmp->left){
                q.push(new TreeBoundaryNode(tmp->left, tmpNode->min, tmp->value));
            }
            if(tmp->right){
                q.push(new TreeBoundaryNode(tmp->right, tmp->value, tmpNode->max));
            }
        }
        else{
            return false;
        }
    }
    return true;
}