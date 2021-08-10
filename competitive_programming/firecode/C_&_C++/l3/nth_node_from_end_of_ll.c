// stdio.h, string.h have been included for this problem.
// You don't need any other header files.

// Add any helper functions(if needed) above.
listNode* find_n_node_from_end(listNode* head, int n)
{   
    if(n <= 0){
        return NULL;
    }
    listNode *tmp1 = head, *tmp2, *prev;
    
    int cnt = 1;
    
    while(cnt < n && tmp1){
        tmp1 = tmp1->next;
        cnt++;
    }
  
    if(cnt < n || !tmp1){
        return NULL;
    }
    
    tmp2 = head;
    prev = NULL;
    
    while(tmp1->next){
        tmp1 = tmp1->next;
        prev = tmp2;
        tmp2 = tmp2->next;
    }
    
    if(!prev){
        return head;
    }
    // prev->next = tmp2->next;
    return tmp2;
    // free(tmp2);
    // return head;
    
}