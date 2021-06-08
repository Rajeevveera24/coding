#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 10

typedef struct S {
	int top;
	int data[MAX];
}S;

empty(S *x){return x->top==-1;}
full(S *x){return x->top==MAX-1;}

init(S* x)
{
	x->top = -1;
	for (int i = 0; i < MAX; i++)
		x->data[i] = -1;
}

void push(S *x, int k)
{
	if (full(x))
		return;
	x->data[x->top++]=k;
}

pop(S *x)
{
	if (empty(x))
		return 0;

	int k = x->data[x->top];
	x->top--;
	return k;
}

void display(S s1, S s2)
{
	int i;
	printf("Printing queue...\n");
	for (i = s2.top; i >= 0; i--)
		printf("%d\n", s2.data[i]);

	for (i = 0; i <= s1.top; i++)
		printf("%d\n", s1.data[i]);
}

int main()
{
	S s1, s2;
	init(&s1);
	init(&s2);

	int m, x;

	for (;;) {
		printf("1. Enqueue.\n");
		printf("2. Dequeue.\n");
		printf("Default. Exit.\n");
		printf("Enter option: ");
		scanf("%d", &m);
		switch(m) {
			case 1:
			fflush(stdin);
			printf("Enter element: ");
			scanf("%d", &x);
			push(&s1, x);
			display(s1, s2);
			break;
			case 2:
			fflush(stdin);
			if (!empty(&s2))
				pop(&s2);
			else {
				while (!empty(&s1)) {
					push(&s2, pop(&s1));
				}

				pop(&s2);
			}
			display(s1, s2);
			break;
			default:
			goto lab;
		}
	}
	lab:
	return 0;
}
