// stdio.h, string.h have been included for this problem.
// You don't need any other header files.

// Add any helper functions(if needed) above.
doublyListNode* insert_at_position( doublyListNode* head, int data,int pos)
{            
    if(!head && pos != 1){
        return NULL;
    }
    
    int cnt = 1;
    
    doublyListNode *newNode = (doublyListNode*)malloc(sizeof(doublyListNode));
    newNode->value = data;
    newNode->next = newNode->prev = NULL;
    
    doublyListNode *tmp = head, *prev = NULL;
    
    while(cnt<pos && tmp){
        cnt++;
        prev = tmp;
        tmp = tmp->next;
    }
    
    if(cnt < pos){
        free(newNode);
        return head;
    }
    
    if(!prev){
        newNode->next = head;
        if(head){
            head->prev = newNode;
        }
        return newNode;
    }
    
    prev->next = newNode;
    newNode->prev = prev;
    newNode->next = tmp;
    if(tmp){
        tmp->prev = newNode;
    }
    
    return head;
}