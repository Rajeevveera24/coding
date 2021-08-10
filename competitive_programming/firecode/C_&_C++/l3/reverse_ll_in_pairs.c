// stdio.h, string.h have been included for this problem.
// You don't need any other header files.

// Add any helper functions(if needed) above.
listNode* reverse_in_pairs(listNode* head) {
    
    if(!head || !head->next){
        return head;
    }
    
    listNode *tmp1, *tmp2, *prev;
    
    tmp1 = head;
    tmp2 = head->next;
    prev = NULL;
    head = head->next;
    
    while(tmp1 && tmp2){
        tmp1->next = tmp2->next;
        tmp2->next = tmp1;
        if(prev){
            prev->next = tmp2;
        }
        prev = tmp1;
        tmp1 = prev->next;
        if(!tmp1){
            break;
        }
        tmp2 = tmp1->next;
        if(!tmp2){
            break;
        }
    }
    return head;
}