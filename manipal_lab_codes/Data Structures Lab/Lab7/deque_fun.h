#define MAX 10
typedef struct {
	char String[MAX][30];
	int r,f;
}dequeue;
void init(dequeue *p);
int empty(dequeue *p);
int full(dequeue *p);
void enqueueR(dequeue *p,char x[30]);
void enqueueF(dequeue *p,char x[30]);
void dequeueF(dequeue *p, char x[30]);
char* dequeueR(dequeue *p);
void print(dequeue *p);
void init(dequeue *p){
	p->r=-1;
	p->f=-1;
}
int empty(dequeue *p){return (p->r==-1);}
int full(dequeue *p){return ((p->r+1)%MAX==p->f);}
void enqueueR(dequeue *p, char x[30]){
	if(empty(p)){
		p->r = p->f = 0;
		strcpy(p->String[0],x);
	}
	else{
		p->r=(p->r+1)%MAX;
		strcpy(p->String[p->r],x);
	}
}
void enqueueF(dequeue *p, char x[30]){
	if(empty(p)){
		p->r = p->f = 0;
		strcpy(p->String[0],x);
	}
	else{
		p->f = (p->f-1+MAX)%MAX;
		strcpy(p->String[p->f],x);
	}
}
void dequeueF(dequeue *p, char x[30]){
	strcpy(x,p->String[p->f]);
	if(p->r==p->f){
		init(p);
	}
	else{
		p->f=(p->f+1)%MAX;
	}
}
char* dequeueR(dequeue *p){
	char x[30];
	strcpy(x,p->String[p->r]);
	if(p->r == p->f){
		init(p);
	}
	else{
		p->r=(p->r-1+MAX)%MAX;
	}
	return x;
}
void print(dequeue *p){
	if(empty(p)){
		printf("Queue is empty\n");
	}
	else{
		int i;
		i=p->f;
		while(i!=p->r){
			printf("\n%s",p->String[i]);
			i=(i+1)%MAX;
		}
		printf("\n%s\n",p->String[p->r]);
	}
}