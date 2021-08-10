// namespace std have been included for this problem.
int max3(int a, int b, int c){
    return (a>b)?(a>c?a:c):(b>c?b:c);
}
int height(treeNode* root){
    if(root){
        int l = height(root->left);
        int r = height(root->right);
        return (l>r)?(1+l):(1+r);
    }
    return 0;
}

// Add any helper functions(if needed) above.
int diameter(treeNode* root)
{
    if(!root){
        return 0;
    }
    
    return max3(diameter(root->right), diameter(root->left), (1 + height(root->left) + height(root->right)));
    
}