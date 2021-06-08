#define MAX 30
typedef struct 
{
	char str[MAX][30];
	int rear,front,size;
}cirque;
void init_cq(cirque *cq, int size){
	cq->rear=-1;
	cq->front=-1;
	cq->size = size;
}
void insertcq(cirque *cq,char str[30]){
	if (cq->rear == -1)
	{
		cq->rear=0;
		cq->front=0;
		strcpy(cq->str[cq->rear],str);
	}
	else if(cq->rear<cq->size-1){
		cq->rear++;
		strcpy(cq->str[cq->rear],str);
	}
	else if(cq->rear>=cq->size-1 && cq->front>0){
		cq->rear = 0;
		strcpy(cq->str[cq->rear],str);
	}
	else if(cq->rear<cq->front){
		(cq->rear)++;
		strcpy(cq->str[cq->rear],str);
	}
	else{
		printf("Queue full\n");
	}
	return;
}
void deletecq(cirque *cq){
	if(cq->front == -1){
		printf("Queue empty\n");
		return;
	}
	else if(cq->front==cq->size-1){
		if(cq->rear==cq->size-1){
			printf("Deleted element is %s\n",cq->str[cq->front]);
			cq->front=cq->rear=-1;
			return;
		}
		else{
			printf("Deleted element is %s\n",cq->str[cq->front]);
			cq->front=0;
			return;
		}
	}
	else{
		printf("Deleted element is %s\n",cq->str[cq->front]);
		cq->front++;
	}
	if(cq->front>cq->rear){
		cq->front=cq->rear=-1;
	}
	return;
}
void displaycq(cirque *cq){
	printf("Elements of the circular queue are:\n");
	if(cq->front==-1){
		printf("Queue Empty\n");
		return;
	}
	if(cq->front<=cq->rear){
		for(int i=cq->front;i<=cq->rear;i++){
			puts(cq->str[i]);
		}
	}
	else{
		for(int i=cq->front;i<cq->size;i++){
			puts(cq->str[i]);
		}
		for(int i=0;i<=cq->rear;i++){
			puts(cq->str[i]);
		}
	}
}