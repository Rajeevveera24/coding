#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// #include "token.h"
#define MAX 80

void proc_E(char *, int *);
void proc_T(char *, int *);
void proc_T1(char *, int *);
void proc_E1(char *, int *);
void proc_F(char *, int *);
int isID(char *, int *);

int isID(char *s, int *p){
	if(s[*p] == 'i' && s[*p + 1] == 'd'){
		(*p)++;
		return 1;
	}
	return 0;
}

void proc_F(char *s, int *pos){
	int p = *pos;
	p++;
	char c = s[p];
	if(c == '('){
		proc_E(s, &p);
		p++; c = s[p];
		if(c == ')'){
			*pos = p;
			return;
		}
		else{
			printf("Rejected\n");
			exit(1);
		}
	}
	else if(isID(s, &p)){
		*pos = p;
		return;
	}
	else{
		printf("Rejected\n");
		exit(1);
	}
}

void proc_T1(char *s, int* pos){
	int p = *pos;
	p++;
	char c = s[p];
	if(c == '*'){
		proc_F(s, &p);
		proc_T1(s, &p);
		*pos = p;
		return;
	}
	else{
		return;
	}
}


void proc_E1(char *s, int *pos){
	int p = *pos;
	p++;
	char c = s[p];
	if(c == '+'){
		proc_T(s, &p);
		proc_E1(s, &p);
		*pos = p;
		return;
	}
	else{
		return;
	}
}

void proc_T(char *s, int *pos){
	int p = *pos;
	// char c = s[p];
	proc_F(s, &p);
	proc_T1(s, &p);
	*pos = p;
	return;
}

void proc_E( char *s, int *pos){
	int p = *pos;
	proc_T(s, &p);
	proc_E1(s, &p);
	*pos = p;
	return;
}


int main(int argc, char const *argv[])
{
	char *s = (char*)malloc(MAX * sizeof(char));
	printf("Enter the string: ");
	scanf("%s", s);
	int a = -1;
	proc_E(s, &a);
	if(a == strlen(s) - 1){
		printf("Accepted\n");
	}
	else{
		printf("Rejected\n");
	}
	return 0;
}