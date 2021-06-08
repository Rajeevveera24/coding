#include <stdio.h>
#include"queue.h"
void search(queue q, int element);
int main(){
	queue q;
	int size,option=1,data;
	printf("Enter the size of the queue: ");
	scanf("%d",&size);
	init_q(&q,size);
	do{
		printf("Enter 1,2,3,0 to add,delete,display and move on respectively\t");
		scanf("%d",&option);
		if(option==1){
			printf("Enter the number to be inserted:\t");
			scanf("%d",&data);
			insert_q(&q,data);
		}
		else if(option==2){
			(delete_q(&q));
		}
		else if(option==3){
			disp_q(&q);
		}
		else{
			break;
		}
	}
	while(option!=0);
	printf("Enter the element to be searched: ");
	scanf("%d",&option);
	search(q,option);
	return 0;
}
void search(queue q,int element){
	queue q1;
	init_q(&q1,q.size);
	for(int i=0;i<q1.size;i++){
		insert_q(&q1,q.data[i]);
	}
	for(int i=0;i<q1.size;i++){
		if(element == delete_q(&q1)){
			printf("Element found\n");
			return;
		}
	}
	printf("Element not found\n");
	return;
}