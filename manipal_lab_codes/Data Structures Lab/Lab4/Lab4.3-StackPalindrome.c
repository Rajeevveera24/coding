#include<stdio.h>
#include<string.h>
#define MAX 30
typedef struct{
	char ch[MAX];
	int top;
}stack;
//Stack Functions
void push(stack *s, char ch);
char pop(stack *s);
//MAIN()
int main(){
	stack s;
	s.top=-1;
	char string[MAX];
	int i,flag=0;
	printf("Enter the string\n");
	gets(string);
	for(i=0;i<strlen(string);i++){
		push(&s,string[i]);
	}
	for(i=0;i<strlen(string);i++){
//		printf("%c\t",pop(&s));
		if(string[i]!=pop(&s)){
			flag=1;
			break;
		}
	}
	if(flag==0)
		printf("String is a Palindrome\n");
	else
		printf("String is not a Palindrome\n");
	return 0;
}
//Function Defenitions
void push(stack *s, char ch){
	if(s->top<MAX-1){
		s->top++;
		s->ch[s->top]=ch;
	}
}
char pop(stack *s){
	if(s->top>=0){
		return s->ch[s->top--];
	}
	else{
		return 0;
	}
}