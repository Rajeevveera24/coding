// stdio.h, string.h have been included for this problem.
// You don't need any other header files.

// Add any helper functions(if needed) above.
int is_cyclic(listNode* head) {
    if(!head || !head->next){
        return 0;
    }
    if(head->next == head){
        return 1;
    }
    listNode *fast = head, *slow = head;
    while(fast->next && fast->next->next){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast){
            return 1;
        }
    }
    return 0;
}