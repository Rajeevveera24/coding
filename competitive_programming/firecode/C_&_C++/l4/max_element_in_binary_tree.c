// stdio.h, string.h have been included for this problem.
// You don't need any other header files.

// Add any helper functions(if needed) above.
int find_max_itr(treeNode *root) {                          
    
    int max = -999;
    
    if(!root){
        return max;
    }
    
    queueTreeNode que;
    queue_treenode_init(&que);
    treeNode *tmp = root;
    treenode_enque(&que, tmp);
    
    while(!is_treequeue_empty(&que)){
        tmp = treenode_deque(&que);
        if(tmp->value > max){
            max = tmp->value;
        }
        if(tmp->left){
            treenode_enque(&que, tmp->left);
        }
        if(tmp->right){
            treenode_enque(&que, tmp->right);
        }
    }
    return max;
}