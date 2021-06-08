#include<stdio.h>
typedef struct
{ 
    int data; 
    struct Node *next; 
}Node; 
  
// To create a new node of circular 
// linked list 
Node *newNode(int data) 
{ 
   Node *temp = (Node*)malloc(sizeof(Node)); 
   temp->next = temp; 
   temp->data = data; 
   return temp;
} 
  
/* Function to find the only person left 
   after one in every m-th node is killed 
   in a circle of n nodes */
void getJosephusPosition(int m, int n) 
{ 
    // Create a circular linked list of 
    // size N. 
    Node *head = newNode(1); 
    Node *prev = head; 
    for (int i = 2; i <= n; i++) 
    { 
        prev->next = newNode(i); 
        prev = prev->next; 
    } 
    prev->next = head; // Connect last 
                       // node to first 
  
    /* while only one node is left in the 
    linked list*/
    Node *ptr1 = head, *ptr2 = head; 
    while (ptr1->next != ptr1) 
    { 
        // Find m-th node 
        int count = 0; 
        while (count <= m) 
        { 
            ptr2 = ptr1; 
            ptr1 = ptr1->next; 
            count++; 
        } 
  
        /* Remove the m-th node */
        ptr2->next = ptr1->next; 
        ptr1 = ptr2->next; 
    } 
  
    printf ("Last person left standing "
            "(Josephus Position) is %d\n ", 
            ptr1->data); 
} 
  
/* Driver program to test above functions */
int main() 
{ 
    int n = 64, m = 0; 
    getJosephusPosition(m, n); 
    return 0; 
}