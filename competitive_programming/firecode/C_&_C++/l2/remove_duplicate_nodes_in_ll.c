// Given a singly-linked list, write a function to delete duplicate nodes in it and 
// return the modified list's head. Be sure to deallocate the memory of the nodes being deleted from the list. 
// Target a worst case space complexity of O(1).


// stdio.h, string.h have been included for this problem.
// You don't need any other header files.

// Add any helper functions(if needed) above.
listNode* remove_duplicates(listNode* head){    
    if(!head){
        return NULL;
    }
    if(!head->next){
        return head;
    }
    
    listNode *tmp = head, *prev, *n;
    
    while(tmp){
        prev = tmp;
        n = tmp->next;
        if(!n){
            break;
        }
        while(n){
            if(n->value == tmp->value){
                prev->next = n->next;
                free(n);
                n = prev->next;
            }
            else{
                prev = n;
                n = n->next;
            }
        }
        tmp = tmp->next;
    }
    return head;
}