// namespace std have been included for this problem.

// Add any helper functions(if needed) above.
listNode* reverse_list(listNode* head)
{
    if(!head || !head->next){
        return head;
    }
    
    listNode *tmp = head, *next = tmp->next, *prev = NULL;
    
    while(next){
        tmp->next = prev;
        prev = tmp;
        tmp = next;
        next = next->next;
    }
    tmp->next = prev;
    return tmp;
}