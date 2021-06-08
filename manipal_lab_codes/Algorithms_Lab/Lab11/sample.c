#include <stdio.h>
#include <stdlib.h>
#include "weightedGraph_utilities.h"

int main(){
	Edge graph[20], mst[10];
	int numEdge = 0, numVertex, choice, src, dest, wt, gSize = 0, mstSize = 0;
	
	printf("Enter the number of vertices: ");
	scanf("%d", &numVertex);

	printf("Enter 1 to add an edge. Enter 0 to stop\n");
	// do{
	// 	printf("Enter choice: ");
	// 	scanf("%d", &choice);
	// 	switch(choice){
	// 		case 1:{
	// 			printf("Enter source, destination and weight: ");
	// 			scanf("%d %d %d", &src, &dest, &wt);
	// 			addEdge(graph, &gSize, src, dest, wt);
	// 			break;
	// 		}
	// 		case 0:{
	// 			break;
	// 		}
	// 		default:{
	// 			printf("Enter proper choice\n");
	// 		}
	// 	}
	// }while( choice != 0);

	addEdge(graph, &gSize, 1,2,3);
	addEdge(graph, &gSize, 2,3,1);
	addEdge(graph, &gSize, 1,5,6);
	addEdge(graph, &gSize, 1,6,5);
	addEdge(graph, &gSize, 2,6,4);
	addEdge(graph, &gSize, 3,4,6);
	addEdge(graph, &gSize, 3,6,4);
	addEdge(graph, &gSize, 4,5,8);
	addEdge(graph, &gSize, 4,6,5);
	addEdge(graph, &gSize, 5,6,2);

	sortEdges(graph, gSize);
	printf("%d\n", gSize);
	printEdges(graph, gSize);
	while(numEdge < gSize){
		if(checkCycle(mst, mstSize, graph[numEdge].src, graph[numEdge].dest) == 0){
			addEdge(mst, &mstSize, graph[numEdge].src, graph[numEdge].dest, graph[numEdge].wt);
			printf("\n");
			printEdges(mst, mstSize);
			printf("\n");
		}
		numEdge++;
	}
	//addEdge(1,2,5);
	//addEdge(1,2,5);
	printf("MST is:\n");
	printEdges(mst, mstSize);
	//printf("%d\n", checkCycle(2,4));
}