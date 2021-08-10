// namespace std have been included for this problem.

// Add any helper functions(if needed) above.
treeNode* find_lca(treeNode* root, int a, int b){
    if(root){
        if(root->value == a || root->value == b){
            return root;
        }
        treeNode *left = find_lca(root->left, a, b), *right = find_lca(root->right, a, b);
        if(left && right){
            return root;
        }
        if(left){
            return left;
        }
        if(right){
            return right;
        }
        return NULL;
        
    }
    return NULL;
}