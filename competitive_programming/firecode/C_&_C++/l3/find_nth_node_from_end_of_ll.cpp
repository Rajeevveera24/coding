// namespace std have been included for this problem.

// Add any helper functions(if needed) above.
listNode* find_n_node_from_end(listNode* head, int n)
{
    if(n<=0 || !head){
        return NULL;
    }
    int cnt = 1;
    listNode *t1 = head;
    
    while(cnt<n && t1){
        cnt++;
        t1 = t1->next;
    }
    
    if(cnt < n || !t1){
        return NULL;
    }
    
    listNode *t2 = head, *prev = NULL;
    
    while(t1->next){
        t1 = t1->next;
        prev = t2;
        t2 = t2->next;
    }
    return t2;
}