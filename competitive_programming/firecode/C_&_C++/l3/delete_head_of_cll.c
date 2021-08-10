// stdio.h, string.h have been included for this problem.
// You don't need any other header files.

// Add any helper functions(if needed) above.
circularListNode* delete_at_head(circularListNode* head)
{
    if(!head){
        return NULL;
    }
    if(head->next == head){
        free(head);
        return NULL;
    }
    circularListNode *tmp = head;
    while(tmp->next != head){
        tmp = tmp->next;
    }
    tmp->next = head->next;
    free(head);
    return tmp->next;
}