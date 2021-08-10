
// Traverse a given binary tree in the Reverse Level Order. 
// Mark each node as visited by calling void visited(treeNode* node) as you traverse each node.

// stdio.h, string.h have been included for this problem.
// You don't need any other header files.

// Add any helper functions(if needed) above.
void level_order_rev(treeNode* root) {                    
    if(!root){
        return;
    }
    
    treeNode *tmp = root;
    
    queueTreeNode q;
    stackTreeNode s;
    
    queue_treenode_init(&q);
    stack_treenode_init(&s);
    
    treenode_enque(&q, tmp);
    // treenode_push(&s, tmp);
    
    while(!is_treequeue_empty(&q)){
        tmp = treenode_deque(&q);
        treenode_push(&s, tmp);
        if(tmp->right){
            treenode_enque(&q, tmp->right);
        }
        if(tmp->left){
            treenode_enque(&q, tmp->left);
        }
    }
    
    while(!is_treestack_empty(&s)){
        tmp = treenode_pop(&s);
        visited(tmp);
    }
}