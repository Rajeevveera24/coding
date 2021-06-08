#include <stdio.h>

#define max 20

int size, graph[max][max], visited[max], push[max], p1 = 0, p2 = 0;
int q[max], f = -1, r = -1;

void enQueue(int n){
	if(r == size - 1){
		return;
	}
	r++;
	q[r] = n;
	if(f == -1){
		f++;
	}
}

void deQueue(){
	if(r == -1 || r < f){
		return;
	}
	f++;
	if(f>r){
		f = r = -1;
	}
}

void inputGraph(){
	for(int i=0; i<size; i++){
		visited[i] = 0;
		for(int j=0; j<size; j++){
			scanf("%d", &graph[i][j]);
		}
	}
}

void bfs(int n){
	visited[n] = 1;
	push[p1++] = n+1;
	enQueue(n);

	// int flag = 0;
	while(r != -1 && f <= r){
		for(int i=0; i<size; i++){
			if(!visited[i]){
				if(graph[q[f]][i]){
					visited[i] = 1;
					push[p1++] = i+1;
					enQueue(i);
				}
			}
		}
		deQueue();
	}
	// pop[p2++] = n+1;
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
			bfs(i);
		}
	}
	display(push, size);
	// display(pop, size);
	return 0;
}