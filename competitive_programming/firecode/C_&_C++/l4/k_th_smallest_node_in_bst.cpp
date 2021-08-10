// namespace std have been included for this problem.
int find_size(treeNode* root){
    if(root){
        return 1 + find_size(root->left) + find_size(root->right);
    }
    return 0;
}
// Add any helper functions(if needed) above.
treeNode* find_kth_smallest(treeNode* root, int k)
{
    if(!root){
        return NULL;
    }
    int size = find_size(root->left);
    if(size == k-1){
        return root;
    }
    else if(size > k-1){
        return find_kth_smallest(root->left, k);
    }
    return find_kth_smallest(root->right, k - (size+1));
}