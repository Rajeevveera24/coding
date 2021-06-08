#include<stdio.h>
#include<stdlib.h>
#include"queue1.h"
int main()
{
	struct Node *head = NULL;
	int option,num;
    printf("Menu:\t1)Insert\t2)Display\t3)Delete\t4)Exit\n");
    do{
        printf("Choice: ");
        scanf("%d",&option);
        if(option == 1){
            printf("Enter Number: ");
            scanf("%d",&num);
            enqueue(&head,num);
        }
        else if(option == 2){
            printq(head);
        }
        else if(option == 3){
        	dequeue(&head);
        }
        else if(option == 4){
            break;
        }
        else{
            printf("Enter proper choice\n");
        }

    }while(option!=4);
	return 0;
}