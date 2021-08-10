// Given a binary tree, write a function to perform the preorder traversal iteratively.
// Mark each node as visited by calling void visited(treeNode* node)

// stdio.h, string.h have been included for this problem.
// You don't need any other header files.

// Add any helper functions(if needed) above.
void preorder_itr(treeNode* root) {                   
    if(!root){
        return;
    }
    stackTreeNode stack;
    stack_treenode_init(&stack);
    
    treeNode* tmp = root;
    
    treenode_push(&stack, tmp);

    while(!is_treestack_empty(&stack)){
        tmp = treenode_pop(&stack);
        visited(tmp);
        while(tmp->left){
            if(tmp->right){
                treenode_push(&stack, tmp->right);
            }
            tmp = tmp->left;
            visited(tmp);
        }
    }
}