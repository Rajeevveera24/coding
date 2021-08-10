// stdio.h, string.h have been included for this problem.
// You don't need any other header files.

// Add any helper functions(if needed) above.
listNode* insert_at_position( listNode* head, int data,int pos){
    
    if(pos <= 0){
        return head;
    }
    
    if(!head && pos>1){
        return NULL;
    }
    
    listNode *new_node = (listNode*)malloc(sizeof(listNode));
    new_node->value = data;
    
    if(pos == 1){
        new_node->next = head;
        return new_node;
    }
    
    int cnt = 1;
    listNode *cur = head, *prev = NULL;
    
    while(cnt < pos && cur){
        prev = cur;
        cur = cur->next;
        cnt++;
    }
    
    if(cnt < pos){
        free(new_node);
        return head;
    }
    
    prev->next = new_node;
    new_node->next = cur;
    return head;
}