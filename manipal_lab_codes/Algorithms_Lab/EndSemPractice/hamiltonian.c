#include <stdio.h>

#define MAX 20

typedef enum {NO, YES} BOOL;

int g[MAX][MAX], size, v[MAX], p, count = 0;

BOOL isPresent(int vertex){
	for(int i=0; i<p; i++){
		count++;
		if(v[i] == vertex){
			return YES;
		}
		if(v[i] == -1){
			break;
		}
	}
	return NO;
}

BOOL addtoPath(int vertex){
	if(!isPresent(vertex)){
		v[p++] = vertex;
		return YES;
	}
	return NO;
}

BOOL isHam(){
	addtoPath(0);
	int i,vertex;
	do{
		int last = v[p-1];
		BOOL added = NO;
		for(vertex=0; vertex<size; vertex++){
			count++;
			if(g[last][vertex]){
				added = added || addtoPath(vertex);
			}
		}
		if(!added){
			return NO;
		}
	}while(p<size);
	if(p == size){
		v[p++] = v[0];
	}
	return YES;
}

int main(int argc, char const *argv[])
{
	for (int i = 0; i < MAX; ++i) {
		v[i] = -1;
	}
	scanf("%d", &size);
	for(int i=0; i<size; i++){
		for(int j=0; j<size; j++){
			scanf("%d", &g[i][j]);
		}
	}
	if (isHam()) {
		printf("Hamiltonian circuit exists: ");
		for (int i = 0; i < p; ++i){
			printf("%d ", v[i]+1);
		}
		printf("\n");
	} 
	else {
		printf("Hamiltonian circuit does not exist.\n");
	}
	printf("%d", count);
	printf("\n");

	return 0;
}