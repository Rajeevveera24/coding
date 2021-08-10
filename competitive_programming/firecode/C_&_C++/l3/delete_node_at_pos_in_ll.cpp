// namespace std have been included for this problem.

// Add any helper functions(if needed) above.
listNode* delete_at_pos(listNode* head, int n)
{
    if(!head || n <= 0){
        return head;
    }
    
    int cnt = 1;
    listNode *tmp = head, *prev = NULL;
    
    while(cnt < n && tmp){
        cnt++;
        prev = tmp;
        tmp = tmp->next;
    }
    
    if(cnt < n || !tmp){
        return head;
    }
    
    if(!prev){
        tmp = head->next;
        free(head);
        return tmp;
        
    }
    prev->next = tmp->next;
    free(tmp);
    return head;
}