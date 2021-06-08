#define MAX 30
typedef struct {
	int data[MAX];
	int rear,front,size;
}queue;
void init_q(queue *q, int size){
	q->rear=q->front=-1;
	q->size = size;
}
void insert_q(queue *q, int data){
	if(q->rear == q->size-1){
		printf("Queue full\n");
		return;
	}
	else{
		q->rear++;
		q->data[q->rear] = data;
	}
	if(q->front==-1){
		q->front=0;
	}
}
int delete_q(queue *q){
	if(q->front>q->rear){
		q->front=q->rear=-1;
		printf("Queue Empty\n");
		return -1;
	}
	else{
		q->front++;
		return (q->data[q->front-1]);
	}
}
void disp_q(queue *q){
	if(q->front>q->rear){
		printf("Queue Empty\n");
		return;
	}
	for(int i=q->front;i<=q->rear;i++){
		printf("%d\t",q->data[i]);
	}
	printf("\n");
}