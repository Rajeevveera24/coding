// namespace std have been included for this problem.

vector<int> preordered_list;
// Add any helper functions(if needed) below.


// Add any helper functions(if needed) above.
void preorder(treeNode* root)
{
    if(root){
        preordered_list.push_back(root->value);
        preorder(root->left);
        preorder(root->right);
    }
    
}