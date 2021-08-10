// Write a function to insert a new node at the head of a circular-linked list and return the modified list's head node.


// stdio.h, string.h have been included for this problem.
// You don't need any other header files.

struct circularListNode{
    int value;                      /* value of the node */
    struct circularListNode* next;  /* next pointer to point next circulary linkedlist node */
};
// Add any helper functions(if needed) above.
circularListNode* insert_at_head( circularListNode* head, int data){
    if(head == NULL){
        head = (circularListNode*)malloc(sizeof(circularListNode));
        head->value = data;
        head->next = head;
        return head;
    }
    circularListNode *tmp = (circularListNode*)malloc(sizeof(circularListNode));
    tmp->value = data;
    tmp->next = head;
    
    circularListNode *tmp1 = tmp;
    
    tmp = head;
    
    while(tmp->next != head){
        tmp = tmp->next;
    }
    tmp->next = tmp1;
    
    return tmp1;
    
}