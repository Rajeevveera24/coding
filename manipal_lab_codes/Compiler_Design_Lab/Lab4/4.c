#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// #include "token.h"
#define MAX 80

void proc_Lexp(char *, int *);
void proc_Atem(char *, int *);
void proc_List(char *, int *);
void proc_LexpSeq(char *, int *);
void proc_A1(char *, int *);
int isID(char *s, int *p);
int isNumber(char *s, int *p);

int isNumber(char *s, int *p){
	if(s[*p + 1] == 'n' && s[*p + 2] == 'u' && s[*p + 3] == 'm'){
		(*p) += 3;
		return 1;
	}
	return 0;
}

int isID(char *s, int *p){
	if(s[*p + 1] == 'i' && s[*p + 2] == 'd'){
		(*p) += 2;
		return 1;
	}
	return 0;
}

void proc_A1(char *s, int *pos){
	printf("Lexp_Seq1\n");
	int p = *pos;
	if(s[p+1] == ')'){
		printf("Accepted\n");
		exit(0);
	}
	proc_Lexp(s, &p);
	proc_A1(s, &p);
	*pos = p;
	return;
}

void proc_LexpSeq(char *s, int* pos){
	printf("Lexp_Seq\n");
	int p = *pos;
	proc_Lexp(s, &p);
	proc_A1(s, &p);
	*pos = p;
	return;
}


void proc_List(char *s, int *pos){
	printf("List\n");
	int p = *pos;
	p++;
	char c = s[p];
	if(c == '('){
		proc_LexpSeq(s, &p);
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
	else{
		printf("Rejected\n");
		exit(1);
	}
}

void proc_Atem(char *s, int *pos){
	printf("Atem\n");
	int p = *pos;
	if(isNumber(s, &p)){
		*pos = p;
		return;
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

void proc_Lexp( char *s, int *pos){
	printf("Lexp\n");
	int p = *pos;
	if(s[p+1] == '('){
		proc_List(s, &p);
		*pos = p;
		return;
	}
	else if(isNumber(s, &p)){
		p -= 3;
		proc_Atem(s, &p);
		*pos = p;
		return;
	}
	else if(isID(s, &p)){
		p -= 2;
		proc_Atem(s, &p);
		*pos = p;
		return;
	}
	else{
		printf("Rejected\n");
		exit(1);
	}
}


int main(int argc, char const *argv[])
{
	char *s = (char*)malloc(MAX * sizeof(char));
	printf("Enter the string: ");
	scanf("%s", s);
	int a = -1;
	proc_Lexp(s, &a);
	if(a == strlen(s) - 1){
		printf("Accepted\n");
	}
	else{
		printf("Rejected\n");
	}
	return 0;
}