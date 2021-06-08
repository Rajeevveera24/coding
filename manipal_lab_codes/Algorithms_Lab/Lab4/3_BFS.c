#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int G[MAXSIZE][MAXSIZE], visited[MAXSIZE], n;

void BFS(int);

int main(){

    printf("Enter number of vertices: ");   
    scanf("%d",&n);

    printf("\nEnter adjecency matrix of the graph:\n");

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&G[i][j]);
        }
    }

    for(int i=0; i<n; i++){
        visited[i]=0;
    }
    //printf("Here\n\n");
    printf("Order of traversal using BFS is: ");

    for(int i=0; i<n; i++){
        if(visited[i] == 0){
            BFS(i);
        }
    }
    printf("\n");
    
    return 0;
}

void BFS(int j){
    printf("%d ",j+1);
    visited[j] = 1;
    int *arr, rear, front;
    arr = (int *)calloc(n, sizeof(int));
    initQueue(&rear, &front);
    enQueue(arr, n, &rear, &front, j);

    while(rear != -1 && front <= rear){//while queue is not empty...
        for(int i=0; i<n; i++){
            if(G[arr[front]][i] == 1){
                if(visited[i] == 0){
                    printf("%d ",i+1);
                    visited[i] = 1;
                    enQueue(arr, n, &rear, &front ,i);
                }
            }
        }
        deQueue(arr, n, &rear, &front);
    }    
}