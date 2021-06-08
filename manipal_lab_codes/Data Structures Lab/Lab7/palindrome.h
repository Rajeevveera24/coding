#define MAX 30
typedef struct {
	char String[MAX];
	int r,f;
}dequeue;
void init(dequeue *p);
int empty(dequeue *p);
int full(dequeue *p);
void enqueueR(dequeue *p,char x);
void enqueueF(dequeue *p,char x);
char dequeueF(dequeue *p);
char dequeueR(dequeue *p);
void print(dequeue *p);
void init(dequeue *p){
	p->r=-1;
	p->f=-1;
}
int empty(dequeue *p){return (p->r==-1);}
int full(dequeue *p){return ((p->r+1)%MAX==p->f);}
void enqueueR(dequeue *p, char x){
	if(empty(p)){
		p->r = p->f = 0;
		p->String[0] = x;
	}
	else{
		p->r=(p->r+1)%MAX;
		p->String[p->r]=x;
	}
}
void enqueueF(dequeue *p, char x){
	if(empty(p)){
		p->r = p->f = 0;
		p->String[0] = x;
	}
	else{
		p->f = (p->f-1+MAX)%MAX;
		p->String[p->f] = x;
	}
}
char dequeueF(dequeue *p){
	char x = p->String[p->f];
	if(p->r==p->f){
		init(p);
	}
	else{
		p->f=(p->f+1)%MAX;
	}
	return x;
}
char dequeueR(dequeue *p){
	char x = p->String[p->r];
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
			printf("%c",p->String[i]);
			i=(i+1)%MAX;
		}
		printf("%c\n",p->String[p->r]);
	}
}