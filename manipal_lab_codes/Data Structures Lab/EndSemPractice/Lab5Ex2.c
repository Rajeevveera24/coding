#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define SIZE 20
typedef struct 
{
	char data[SIZE];
	int top;
}stack;

void push(stack*s,char data){
	if(s->top<SIZE-1){
		s->data[++(s->top)] = data;
	}
}
char pop(stack *s){
	if(s->top>=0){
		char c = (s->data[s->top]);
		(s->top)--;
		return c;
	}
}
int precedence(char a, char b){
	if(a == ')' || a == '('){
		return 0;
	}
	if(a == b){
		return 1;
	}
	if(a == '^'){
		return 1;
	}
	if((a == '/' || a == '*') && (b != '^')){
		return 1;
	}
	if(b == '-' || b == '+'){
		return 1;
	}
	return 0;
}
int main(){
	char ch,temp;
	int i;
	stack s,exp_prefix;
	exp_prefix.top = -1;
	s.top = -1;
	char exp_infix[SIZE];
	printf("Enter the infix expression\n");
	scanf("%s",exp_infix);
	for(i = strlen(exp_infix)-1; i>=0; i--){

		ch = exp_infix[i];
		//printf("%c\n",ch);

		if(ch==')'){
			push(&s,ch);
		}
		else if(ch =='('){
			do{
				temp = pop(&s);

				if(temp == ')'){
					break;
				}
				//printf("Here\n");
				push(&exp_prefix,temp);
			}while(1);
		}

		else if(isalnum(ch)){
			push(&exp_prefix,ch);
			//printf("Here");
		}

		else{
			while(precedence(s.data[s.top],ch)>0){
				temp = pop(&s);
				push(&exp_prefix,ch);
			}
			push(&s,ch);
		}

	}

	for(int i=exp_prefix.top;i>=0;i--){
		printf("%c",exp_prefix.data[i]);
	}

	printf("\n");
	return 0;
}