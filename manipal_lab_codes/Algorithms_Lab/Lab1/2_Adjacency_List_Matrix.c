#include <stdio.h>
#include <stdlib.h>

//Defining the basic data structures needed ...
struct adjListNode{
	int dest;
	struct adjListNode* next;
};

struct adjList{
	struct adjListNode* head;
};

struct graph{
	int vertex;
	struct adjList* array; 
};

//Function Declarations...
//For adjacency List..
struct adjListNode* createAdjListNode(int dest);
struct graph* createGraph(int vertex);
void addEdge(struct graph* Graph, int src, int dest);
void printGraph(struct graph* Graph);
//For adjacency matrix..
int** createAdjMatrix(int vertex);
void printAdjMatrix(int **mat, int vertex);

//main() starts here...
int main()
{
	int choice,adjListVertex,adjMatrixVertex,v1,v2,temp;
	struct graph* Graph = NULL;
	int** matrix = NULL;


	do{
		printf("\n===================================MENU=========================================\n\n");
		printf("1. Create a graph using adjacency list representation\n");
		printf("2. Display the adjacency list\n");
		printf("3. Delete the adjacency list\n");
		printf("4. Create a graph using adjacency matrix representation\n");
		printf("5. Display the adjacency matrix\n");
		printf("6. Delete the adjacency matrix\n");
		printf("7. Exit the program\n");
		printf("\nEnter you choice:\t");
		scanf("%d",&choice);

		switch(choice){
			case 1:{
				if(Graph != NULL){
					printf("Adjacency list already exists. Please delete it to create another one.\n");
				}
				else{
					printf("Enter the number of vertices in the graph:\t");
					scanf("%d",&adjListVertex);
					Graph = createGraph(adjListVertex);

					do{
						printf("Press 1 to add an edge and 0 to stop:\t");
						scanf("%d",&temp);
						if(temp == 1){
							printf("Enter the pair of vertices to be connected:\t");
							scanf("%d %d",&v1,&v2);
							addEdge(Graph,v1-1,v2-1);
						}
					}while(temp != 0);
				}
			}
			break;

			case 2:{
				printGraph(Graph);
			}
			break;

			case 3:{
				printf("Deleting adjacency list...\n");
				struct graph* temp = Graph;
				free(temp);
				Graph = NULL;
			}
			break;

			case 4:{
				if(matrix != NULL){
					printf("Adjacency matrix already exists. Please delete it to create another one.\n");
				}
				else{
					printf("Enter the number of vertices in the graph:\t");
					scanf("%d",&adjMatrixVertex);
					matrix = createAdjMatrix(adjMatrixVertex);
				}
			}
			break;

			case 5:{
				printAdjMatrix(matrix,adjMatrixVertex);
			}
			break;

			case 6:{
				printf("Deleting adjacency matrix...\n");
				int** temp = matrix;
				free(temp);
				matrix = NULL;
			}
			break;

			case 7:{
				printf("\nGoodbye...\n");
			}
			break;

			default:{
				printf("\nInvalide choice. Please enter a different choice next time...\n");
			}
			break;
		}

	}while(choice != 7);
	return 0;
}
//End of main()...

//Function Definitions...

//Functions for adjacency list...

struct adjListNode* createAdjListNode(int dest){	//This function creates a node of an adjacency list and stores the value of dest in it...
	struct adjListNode* newNode = (struct adjListNode*)malloc(sizeof(struct adjListNode));
	newNode->dest = dest;
	newNode->next = NULL;
	return newNode;
}

struct graph* createGraph(int vertex){	//This function returns an empty graph by allocating memory for required number of vertices...
	struct graph* Graph = (struct graph*)malloc(sizeof(struct graph));
	
	Graph->vertex = vertex;
	Graph->array = (struct adjList*)malloc(vertex * (sizeof(struct adjList)));

	for(int i=0;i<vertex;i++){
		Graph->array[i].head = NULL;
	}
	return Graph;
}

void addEdge(struct graph* Graph, int src, int dest){	//Adds an edge between any two vertices of the graph...
	struct adjListNode* newNode = createAdjListNode(dest);
	newNode->next = Graph->array[src].head;
	Graph->array[src].head = newNode;
}

void printGraph(struct graph* Graph){	//Prints the adjacecny list...

	if(Graph == NULL){
		printf("Adjacency list does not exist...\n");
		return;
	}
	printf("Printing the adjacency list...\n\n");

	for(int i=0;i<Graph->vertex;i++){
		struct adjListNode* temp = Graph->array[i].head;

		printf("\nAdjacency list of vertex %d\nhead ", i);

		while(temp){
			printf("-> %d",temp->dest);
			temp = temp->next;
		}
		printf("\n");
	}
}
//Function for adjacency matrix...
int **createAdjMatrix(int vertex){	//This functions returns a pointer to an adjacecny matrix. It asks the user to enter values and creates a complete matrix...
	int i, j, v;
	int ** mat = (int **)calloc(vertex, sizeof(int *));

	for (i = 0; i < vertex; ++i){
		
		*(mat + i) = (int *)calloc(vertex, sizeof(int));
		
		for (j = 0; j < vertex; ++j){
			*(*(mat + i) + j) = 0;
		}
	}

	for (i = 0; i < vertex; ++i) {
		printf("\n\tVertex %d, Enter the connected vertices (1 - %d), 0 to break: ", i+1, vertex);
		do {
			scanf(" %d", &v);
			if (v != 0) {
				*(*(mat + i) + (v-1)) = 1;
			}
		} while (v != 0);
	}
	return mat;
}

void printAdjMatrix(int **mat, int vertex){	//Prints the given adjacency matrix...

	if(mat == NULL){
		printf("Adjacency matrix does not exist...\n");
		return;
	}
	printf("Printing the adjacency matrix...\n\n");
	int i, j;
	for (i = 0; i < vertex; i++){
		printf("\n\t %d | ", i+1);
		for (j = 0; j < vertex; ++j) {
			printf(" %d ",*(*( mat + i ) + j));
		}
	}
}

//End of Code...


