// Write a function to insert a node at the end of a doubly-linked list and return the head of the modified list.

// stdio.h, string.h have been included for this problem.
// You don't need any other header files.

// Add any helper functions(if needed) above.
doublyListNode*  insert_at_tail( doublyListNode* head, int data){            
    doublyListNode *tmp = (doublyListNode*)malloc(sizeof(doublyListNode));
    tmp->value = data;
    tmp->next = tmp->prev = NULL;
    if(!head){
        return tmp;
    }
    doublyListNode *tmp2 = head;
    while(tmp2->next){
        tmp2 = tmp2->next;
    }
    tmp2->next = tmp;
    tmp->prev = tmp2;
    return head;
}