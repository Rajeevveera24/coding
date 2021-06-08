#include <stdio.h>

#define MAXSIZE 10 
int G[MAXSIZE][MAXSIZE], visited[MAXSIZE], n;

void DFS(int);
 
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

    printf("Order of traversal using DFS is: ");

    for(int i=0; i<n; i++){
        if(visited[i] == 0){
            DFS(i);
        }
    }
    printf("\n");
    
    return 0;
}

void DFS(int i){

    int j;
    printf("%d ", i+1);

    visited[i]=1;

    for(j=0;j<n;j++){
        if(!visited[j]&&G[i][j]==1){
            DFS(j);
        }
    }
}