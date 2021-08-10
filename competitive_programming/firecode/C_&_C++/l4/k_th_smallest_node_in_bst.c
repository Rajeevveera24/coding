// stdio.h, string.h have been included for this problem.
// You don't need any other header files.

// Add any helper functions(if needed) above.
treeNode* find_kth_smallest(treeNode* root, int k) {                   
    if(!root){
        return NULL;
    }
    
    int size = tree_size(root->left);
    
    if(size == k-1){
        return root;
    }
    
    if(size >= k){
        return find_kth_smallest(root->left, k);
    }
    
    return find_kth_smallest(root->right, k-size-1);
}