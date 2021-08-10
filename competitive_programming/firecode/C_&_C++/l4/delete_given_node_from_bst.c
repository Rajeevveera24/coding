// Write a function to delete a node from a given a binary search tree.
// Be sure to deallocate the memory of the tree node to be deleted. Return the root node of the tree.

// stdio.h, string.h have been included for this problem.
// You don't need any other header files.

// Add any helper functions(if needed) above.
treeNode* delete_node(treeNode* root, int data) {                    
    if(!root){
        return NULL;
    }
    if(root->value > data){
        root->left = delete_node(root->left, data);
    }
    else if(root->value < data){
        root->right = delete_node(root->right, data);
    }
    
    else{
        if(!root->left && !root->right){
            free(root);
            return NULL;
        }
    
        treeNode *tmp, *t1;
    
        if(!root->left){
            tmp = root;
            root = root->right;
            free(tmp);
        }
        else if(!root->right){
            tmp = root->left;
            free(root);
            root = tmp;
        }
        else{
            tmp = root->right;
            
            if(!tmp->left){
                tmp->left = root->left;
                free(root);
                root = tmp;
            }
            else{
                while(tmp->left){
                    tmp = tmp->left;
                }
                tmp->left = root->left;
                t1 = tmp->right;
                if(!t1){
                    tmp->right = root->right;
                }
                else{
                    while(t1->right){
                        t1 = t1->right;
                    }
                    t1->right = root->right;
                }
                free(root);
                root = tmp;
            }
        }
    }
    return root;
}