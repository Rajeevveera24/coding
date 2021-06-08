#define MAX 10
typedef struct {
	int data[MAX];
	int r,f;
}queue;
typedef struct 
{
	int data[MAX];
	int top;
}stack;
void inits(stack *s){
	s->top=-1;
}
int emptys(stack *s){return(s->top==-1);}
int fulls(stack *s){return(s->top==MAX-1);}
void push(stack *s,int x){
	if(fulls(s)){
		return;
	}
	else{
		s->top+=1;
		s->data[s->top]=x;
	}
}
int pop(stack *s){
	if(!emptys(s)){
		int x = s->data[s->top];
		s->top-=1;
		return x;
	}
}
void init(queue *p){
	p->r=-1;
	p->f=-1;
}
int empty(queue *p){return (p->r==-1);}
int full(queue *p){return ((p->r+1)%MAX==p->f);}
void enqueue(queue *p, int x){
	if(empty(p)){
		p->r = p->f = 0;
		p->data[0] = x;
	}
	else{
		p->r=(p->r+1)%MAX;
		p->data[p->r]=x;
	}
}
int dequeue(queue *p){
	int x = p->data[p->f];
	if(p->r==p->f){
		init(p);
	}
	else{
		p->f=(p->f+1)%MAX;
	}
	return x;
}
void print(queue *p){
	if(empty(p)){
		printf("Queue is empty\n");
	}
	else{
		int i;
		i=p->f;
		while(i!=p->r){
			printf("%d\t",p->data[i]);
			i=(i+1)%MAX;
		}
		printf("%d\n",p->data[p->r]);
	}
}