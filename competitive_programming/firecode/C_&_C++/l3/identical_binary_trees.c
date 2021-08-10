// Given two binary trees, determine if they are identical. If they are, return 1 otherwise return 0. If both the trees are empty, they are identical.

// stdio.h, string.h have been included for this problem.
// You don't need any other header files.

// Add any helper functions(if needed) above.
int is_identical(treeNode* root1, treeNode* root2) {                   
    if(!root1 && !root2){
        return 1;
    }
    if(!root1 || !root2){
        return 0;
    }
    return (root1->value == root2->value) && (is_identical(root1->left, root2->left) && is_identical(root1->right, root2->right)); 
}