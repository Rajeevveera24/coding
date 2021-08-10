// stdio.h, string.h have been included for this problem.
// You don't need any other header files.

// Add any helper functions(if needed) above.
int is_mirror(treeNode* root1, treeNode* root2) {                   
    if(!root1 && !root2){
        return 1;
    }
    if(!root1 || !root2){
        return 0;
    }
    
    return (root1->value == root2->value) && is_mirror(root1->left, root2->right) && is_mirror(root1->right, root2->left);
}