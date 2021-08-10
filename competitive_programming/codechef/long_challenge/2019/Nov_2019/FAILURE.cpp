#include <iostream>
using namespace std;

int t, n, m, x, y;
int **graph, *p;

int dfs(int x, int y, int visited[]){
	visited[x] = 1;
	int flag = 0;
	for(int i=0; i<n; i++){
		if(i==y){
			continue;
		}
		if(graph[x][i] == 1){
			if(visited[i] == 1){
				return 1;
			}
			else{
				flag = dfs(i, x, visited);
				if(flag){
					return flag;
				}
			}
		}
	}
	return flag;
}

bool isCycle(){
	int flag = 0;
	int *visited = (int*)malloc(sizeof(int) * n);
	for(int i=0; i<n; i++){
		visited[i] = 0;
	}
	for(int i=0; i<n; i++){
		if(!visited[i]){
			int flag = dfs(i, i, visited);
			if(flag == 1){
				return true;
			}
		}
	}
	free(visited);
	return false;
}

void printGraph(){
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cout<<graph[i][j]<<" ";
		}
		cout<<endl;
	}
}

int main() {
	cin >> t;
	while(t--){
		cin >> n >> m;
		graph = (int**)malloc(sizeof(int*) * n);
		for(int i=0; i<n; i++){
			graph[i] = (int*)malloc(sizeof(int) * n);
			for(int j=0; j<n; j++){
				graph[i][j] = 0;
			}
		}
		// p = (int**)malloc(sizeof(int*) * m);
		for(int i=0; i<m; i++){
			cin >> x >> y;
			graph[x-1][y-1] = 1;
			graph[y-1][x-1] = 1;
		}
		// printGraph();
		if(!isCycle()){
			cout<<-1<<endl;
		}
		else{
			int flag = -1;
			for(int i=0; i<n; i++){
				p = (int*)malloc(sizeof(int) * n);
				// pCount = 0;
				for(int j=0; j<n; j++){
					p[j] = graph[i][j];
					graph[i][j] = 0;
					graph[j][i] = 0;
				}
				if(!isCycle()){
					flag = i+1;
					break;
				}
				for(int j=0; j < n; j++){
					graph[i][j] = p[j];
					graph[j][i] = p[j]; 
				}
				free(p);
			}
			cout<<flag<<endl;
		}
		free(graph);
	}
	return 0;
}
