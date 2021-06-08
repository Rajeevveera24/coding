//This is a C Program to Implement two Stacks using a Single Array & Check for Overflow & Underflow
#include <stdio.h>
#define SIZE 10
int ar[SIZE];
int top1 = -1;
int top2 = SIZE;
//Functions to push data
void push_stack1 (int data)
{
        if (top1 < top2 - 1)
        {
                ar[++top1] = data;
        }
        else
        {
                        printf ("Stack Full! Cannot Push\n");
        }
}
void push_stack2 (int data)
{
        if (top1 < top2 - 1)
        {
                ar[--top2] = data; 
        }
        else
        {
                printf ("Stack Full! Cannot Push\n");
        }
}
//Functions to pop data
void pop_stack1 ()
{
        if (top1 >= 0)
        {
                int popped_value = ar[top1--];
                printf ("%d is being popped from Stack 1\n", popped_value);
        }
        else
        {
                printf ("Stack Empty! Cannot Pop\n");
        }
}
void pop_stack2 ()
{
        if (top2 < SIZE)
        {
                int popped_value = ar[top2++];
                printf ("%d is being popped from Stack 2\n", popped_value);
        }
        else
        {
                printf ("Stack Empty! Cannot Pop\n");
        }
}
//Functions to Print Stack 1 and Stack 2
void print_stack1 ()
{
        int i;
        for (i = top1; i >= 0; --i)
        {
                printf ("%d ", ar[i]);
        }
        printf ("\n");
}
void print_stack2 ()
{
        int i;
        for (i = top2; i < SIZE; ++i)
        {
                printf ("%d ", ar[i]);
        }
        printf ("\n");
}
int main()
{
        int ar[SIZE];
        int i,num,option;
        do{
                printf("Enter 1,2,3,0 to push,pop,display and exit respectively: ");
                scanf("%d",&option);
                switch(option){
                        case 1:{
                                printf("Enter 1 for stack 1 and 2 for stack 2\n");
                                scanf("%d",&i);
                                if(i==1){
                                        printf("Enter Number: ");
                                        scanf("%d",&num);
                                        push_stack1(num);
                                }
                                else if(i==2){
                                        printf("Enter Number: ");
                                        scanf("%d",&num);
                                        push_stack2(num);
                                }
                                else{
                                        printf("Enter proper stack number\n");
                                }
                        }
                        break;
                        case 2:{
                                printf("Enter 1 for stack 1 and 2 for stack 2\n");
                                scanf("%d",&i);
                                if(i==1){
                                        pop_stack1();
                                }
                                else if(i==2){
                                        pop_stack2();
                                }
                                else{
                                        printf("Enter proper stack number\n");
                                }    
                        }
                        break;
                        case 3:{
                                printf("First Stack:\t");
                                print_stack1();
                                printf("Second Stack:\t");
                                print_stack2();
                        }
                        break;
                        default:
                        break;
                }
        }while(option!=0);
        return 0;
}