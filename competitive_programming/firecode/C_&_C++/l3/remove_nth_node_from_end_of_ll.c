// Given a singly-linked list, write a function to delete the nth from the end node of the list without using extra memory.
// If the nth node is not present or if the list is empty, return NULL.
// Be sure to deallocate the memory of the node getting deleted from the list.



// stdio.h, string.h have been included for this problem.
// You don't need any other header files.

// Add any helper functions(if needed) above.
listNode* remove_nth_from_end(listNode* head, int n){    
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
        tmp2 = head->next;
        free(head);
        return tmp2;
    }
    prev->next = tmp2->next;
    free(tmp2);
    return head;
        
}