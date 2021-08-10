// Given a binary tree, write a function to find and return the node with data = the input data. Do not use recursion. If the node is not found, return NULL

// stdio.h, string.h have been included for this problem.
// You don't need any other header files.

// Add any helper functions(if needed) above.
treeNode* find_node_itr(treeNode *root, int data) {                   
    if(!root){
        return NULL;
    }
    treeNode *tmp = root;
    queueTreeNode que;
    queue_treenode_init(&que);
    treenode_enque(&que, tmp);
    
    while(!is_treequeue_empty(&que)){
        tmp = treenode_deque(&que);
        if(tmp->value == data){
            queue_treenode_destroy(&que);
            return tmp;
        }
        if(tmp->left){
            treenode_enque(&que, tmp->left);
        }
        if(tmp->right){
            treenode_enque(&que, tmp->right);
        }
    }
    return NULL;
}