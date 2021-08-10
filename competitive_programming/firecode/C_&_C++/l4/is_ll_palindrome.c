// Write a function to determine if a given singly-linked list is a palindrome. 
// Return 1 if it is a palindrome, else return 0. An empty list is not a palindrome. 
// Use the provided APIs.

// stdio.h, string.h have been included for this problem.
// You don't need any other header files.

// Add any helper functions(if needed) above.
int is_list_palindrome(listNode* head){   
    if(!head){
        return 0;
    }
    if(!head->next){
        return 1;
    }
    
    int odd = 0;
    listNode *tmp, *f = head, *s = head;
    
    while(f->next && f->next->next){
        f = f->next->next;
        s = s->next;
    }
    if(!f->next){
        odd = 1;
    }
    else{
        odd = 0;
    }
    
    tmp = s->next;
    listNode *newList = NULL;
    
    while(tmp){
        list_insert_at_start(&newList, tmp->value);
        tmp = tmp->next;
    }
    
    s = head;
    f = newList;
    
    while(f){
        if(s->value != f->value){
            list_delete(&newList);
            return 0;
        }
        s = s->next;
        f = f->next;
    }
    list_delete(&newList);
    return 1;
    // return 0;
}