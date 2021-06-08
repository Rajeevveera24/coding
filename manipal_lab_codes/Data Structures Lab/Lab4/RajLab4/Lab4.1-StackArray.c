#include<stdio.h>
#define MAX 30
/*defenition of structure stack: It has a character array of MAX elements at maximum and the int top, 
								 representing the highest occupied position in the character array*/
typedef struct{
	int ch[MAX];
	int top;
}stack;
//list of functions operating on stack
void push(stack *s, char ch);
char pop(stack *s);
void display(stack *s);
int over_flow(stack *s);
int under_flow(stack *s);
//main() starts here. To see the functions, go to LINE #54
int main(){
	stack s;
	s.top=-1;
	int option;
	char ch;
	do{
		printf("Enter 0,1,2,3 to exit,push,pop and display respectively\n");
		option=0;
		scanf("%d",&option);
		switch(option){
			case 1:{
				printf("Enter the character:\t");
				scanf("\t%c",&ch);
				push(&s,ch);
			}
			break;
			case 2:{
				ch=pop(&s);
				if(ch!=0){
					printf("The deleted element is %c\n",ch);
				}
			}
			break;
			case 3:{
				display(&s);
			}
			break;
			case 0:
			break;
			default:{
				printf("Enter proper character\n");
			}
			break;
		}
	}while(option!=0);
	return 0;
}
//push() function:Calls function over_flow() before adding new element to the stack
void push(stack *s, char ch){
	if(!over_flow(s)){
		s->top++;
		s->ch[s->top]=ch;
	}
}
//pop() function:Calls funtion under_flow() before deleting an element
char pop(stack *s){
	if(!under_flow(s)){
		return s->ch[s->top--];
	}
	else{
		return 0;
	}
}
//display() function:calls function under_flow before displaying the elements of stack
void display(stack *s){
	if(!under_flow(s)){
		int i;
		printf("Elements of stack are:\t");
		for(i=s->top;i>=0;i--){
			printf("%c\t",s->ch[i]);
		}
		printf("\n");
	}
}
//over_flow() function:returns 1 if stack is full and 0 otherwise
int over_flow(stack *s){
	if(s->top<=MAX-1){
		return 0;
	}
	else{
		printf("Stack Overflow\n");
		return 1;
	}
}
//under_flow() function: return 1 if stack is empty and 0 otherwise
int under_flow(stack *s){
	if(s->top>=0){
		return 0;
	}
	else{
		printf("Stack Empty\n");
		return 1;
	}
}