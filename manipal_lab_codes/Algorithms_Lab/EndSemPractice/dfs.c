#include <stdio.h>

#define max 20

int size, graph[max][max], visited[max], pop[max], push[max], p1 = 0, p2 = 0;

void inputGraph(){
	for(int i=0; i<size; i++){
		visited[i] = 0;
		for(int j=0; j<size; j++){
			scanf("%d", &graph[i][j]);
		}
	}
}

void dfs(int n){
	visited[n] = 1;
	push[p1++] = n+1;
	// int flag = 0;
	for(int i=0; i<size; i++){
		if(!visited[i]){
			if(graph[n][i]){
				// flag = 1;
				dfs(i);
			}
		}
	}
	pop[p2++] = n+1;
}

void display(int a[], int size){
	printf("\n");
	for(int i=0; i<size; i++){
		printf("%d ",a[i]);
	}
	printf("\n");
}
int main(int argc, char const *argv[])
{
	scanf("%d", &size);
	inputGraph();
	for(int i=0; i<size; i++){
		if(!visited[i]){
			dfs(i);
		}
	}
	display(push, size);
	display(pop, size);
	return 0;
}