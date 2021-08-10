// stdio.h, string.h have been included for this problem.
// You don't need any other header files.

// Add any helper functions(if needed) above.
int min_depth(treeNode* root) {                    
    if(!root){
        return 0;
    }
    
    int depth = 1;
    
    queueTreeNode que;
    queue_treenode_init(&que);
    
    treeNode *tmp = root;
    
    treenode_enque(&que, tmp);
    
    treeNode *tmp2 = (treeNode*)malloc(sizeof(treeNode));
    tmp2->left = tmp2->right = NULL;
    
    treenode_enque(&que, tmp2);
    
    while(!is_treequeue_empty(&que)){
        
        tmp = treenode_deque(&que);
        
        if(tmp == tmp2){
            if(is_treequeue_empty(&que)){
                free(tmp2);
                free(tmp);
                queue_treenode_destroy(&que);
                return depth;
            }
            depth++;
            treenode_enque(&que, tmp2);
            tmp = treenode_deque(&que);
        }
        
        if(!tmp->left && !tmp->right){
            free(tmp2);
            free(tmp);
            queue_treenode_destroy(&que);
            return depth;
        }
        if(tmp->left){
            treenode_enque(&que, tmp->left);
        }
        if(tmp->right){
            treenode_enque(&que, tmp->right);
        }
    }
    free(tmp2);
    free(tmp);
    queue_treenode_destroy(&que);
    return depth;
}
