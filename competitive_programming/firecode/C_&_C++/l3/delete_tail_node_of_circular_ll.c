// Given a circular-linked list, write a function to delete its tail node and return the modified list's head. 
// For an empty list return NULL. Be sure to deallocate the memory used for the node.


// stdio.h, string.h have been included for this problem.
// You don't need any other header files.

// Add any helper functions(if needed) above.
circularListNode* delete_at_end(circularListNode* head)
{
    if(!head){
        return NULL;
    }    
    if(head->next == head){
        free(head);
        return NULL;
    }
    circularListNode *tmp = head, *prev = NULL;
    
    while(tmp->next != head){
        prev = tmp;
        tmp = tmp->next;
    }
    
    prev->next = head;
    free(tmp);
    return head;
}