// stdio.h, string.h have been included for this problem.
// You don't need any other header files.

// Add any helper functions(if needed) above.
treeNode* find_deepest(treeNode* root) {                    
    if(!root){
        return NULL;
    }
    queueTreeNode que;
    treeNode *tmp = root;
    queue_treenode_init(&que);
    treenode_enque(&que, tmp);
    
    while(!is_treequeue_empty(&que)){
        tmp = treenode_deque(&que);
        
        if(tmp->left){
            treenode_enque(&que, tmp->left);
        }
        if(tmp->right){
            treenode_enque(&que, tmp->right);
        }
    }
    return tmp;
}