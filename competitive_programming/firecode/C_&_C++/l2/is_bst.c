// stdio.h, string.h have been included for this problem.
// You don't need any other header files.

/* Global variables available (as helper). Do not modify them  */
int MIN_VAL =-999, MAX_VAL = 999;
/* write helper function(If needed) below this line only. */
int is_bst(treeNode *root, int min, int max){
    if(root){
        return (root->value < max && root->value > min) && is_bst(root->left, min, root->value) && is_bst(root->right, root->value, max);
    }
    return 1;
}


/* write helper functions above this line only. */
int validate(treeNode* root)
{   
    if(!root){
        return 0;
    }
    return is_bst(root, MIN_VAL, MAX_VAL);
}