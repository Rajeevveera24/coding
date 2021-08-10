// stdio.h, string.h have been included for this problem.
// You don't need any other header files.

// Add any helper functions(if needed) above.
treeNode* find_kth_largest(treeNode* root, int k) {                   
    if(!root){
        return NULL;
    }
    int size = tree_size(root->right);
    if(size + 1 == k){
        return root;
    }
    if(size >= k){
        return find_kth_largest(root->right, k);
    }
    return find_kth_largest(root->left, k-size-1);
}