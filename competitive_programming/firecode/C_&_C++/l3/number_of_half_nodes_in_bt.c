// stdio.h, string.h have been included for this problem.
// You don't need any other header files.

// Add any helper functions(if needed) above.
int number_of_half_nodes(treeNode* root) {                    
    if(!root){
        return 0;
    }
    return ((!root->left && root->right) ||  (root->left && !root->right)) + number_of_half_nodes(root->left) + number_of_half_nodes(root->right);
}