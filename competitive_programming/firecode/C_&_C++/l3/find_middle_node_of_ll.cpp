// namespace std have been included for this problem.

// Add any helper functions(if needed) above.
listNode* find_middle_node(listNode* head)
{
    
    listNode *slow = head, *fast = head;
    
    while(fast && fast->next && fast->next->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}