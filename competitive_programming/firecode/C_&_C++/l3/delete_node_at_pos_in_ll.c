// stdio.h, string.h have been included for this problem.
// You don't need any other header files.

// Add any helper functions(if needed) above.
listNode* delete_at_pos(listNode* head, int n)
{ 
    if(!head){
        return NULL;
    }
    if(n == 1){
        listNode *tmp = head->next;
        free(head);
        return tmp;
    }
    
    int count = 1;
    listNode *tmp = head, *prev;
    
    while(count < n && tmp){
        prev = tmp;
        tmp = tmp->next;
        count++;
    }
    
    if(count == n){
        prev->next = tmp->next;
        free(tmp);
    }
    return head;
}