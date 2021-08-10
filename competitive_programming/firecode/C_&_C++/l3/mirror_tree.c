// Write a function to convert a binary tree into its mirror image and return the root node of the mirrored tree.


// stdio.h, string.h have been included for this problem.
// You don't need any other header files.

// Add any helper functions(if needed) above.
treeNode* mirror(treeNode* root) {                   
    if(root){
        mirror(root->left);
        mirror(root->right);
        treeNode *tmp = NULL;
        tmp = root->left;
        root->left = root->right;
        root->right = tmp;
    }
    return root;
}