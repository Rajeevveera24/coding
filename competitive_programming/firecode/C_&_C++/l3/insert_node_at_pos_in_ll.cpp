// namespace std have been included for this problem.

// Add any helper functions(if needed) above.
listNode* insert_at_position( listNode* head, int data,int pos)
{
    if(pos <= 0){
        return head;
    }
    if(!head && pos>1){
        return head;
    }
    if(pos == 1){
        listNode *tmp = new listNode;
        tmp->value = data;
        tmp->next = head;
        return tmp;
    }
    
    int cnt = 1;
    listNode *tmp = head, *prev = NULL;
    
    while(cnt < pos && tmp){
        cnt++;
        prev = tmp;
        tmp = tmp->next;
    }
    
    if(cnt<pos && !tmp){
        return head;
    }
    
    prev->next = new (listNode);
    prev->next->value = data;
    prev->next->next = tmp;
    
    return head;
    
}