// stdio.h, string.h have been included for this problem.
// You don't need any other header files.

// Add any helper functions(if needed) above.
listNode* add_two_Numbers(listNode* input1, listNode* input2){
    if(!input1 && !input2){
        return NULL;
    }
    if(!input1){
        return input2;
    }
    if(!input2){
        return input1;
    }
    int val = 0;
    // listNode *i1 = input1, *i2 = input2;
    // listNode *t1 = (listNode*)malloc(sizeof(listNode));
    listNode *t1 = NULL, *t2, *t3;
    
    while(input1 && input2){
        val += input1->value + input2->value;
        t3 = (listNode*)malloc(sizeof(listNode));
        t3->value = val%10;
        t3->next = NULL;
        if(!t1){
            t1 = t3;
            t2 = t1;
        }
        else{
            t1->next = t3;
            t1 = t3;
        }
        val /= 10;
        input1=input1->next;
        input2 = input2->next;
    }
    while(input1){
        val += input1->value;
        t3 = (listNode*)malloc(sizeof(listNode));
        t3->value = val%10;
        t3->next = NULL;
        t1->next = t3;
        t1 = t3;
        val /= 10;
        input1=input1->next;
        // i2 = i2->next;
    }
    while(input2){
        val += input2->value;
        t3 = (listNode*)malloc(sizeof(listNode));
        t3->value = val%10;
        t3->next = NULL;
        t1->next = t3;
        t1 = t3;
        val /= 10;
        input2=input2->next;
    }
    if(val != 0){
        t3 = (listNode*)malloc(sizeof(listNode));
        t3->value = val;
        t3->next = NULL;
        t1->next = t3;
    }
    return t2;
}