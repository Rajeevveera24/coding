#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// #include "token.h"
#define MAX 80

void proc_S(char *, int *);
void proc_A(char *, int *);
void proc_A1(char *, int *);
void proc_B(char *, int *);

void proc_B(char *s, int* pos){
	int p = *pos;
	p++;
	char c = s[p];
	if(c == 'd'){
		*pos = p;
		return;
	}
	else{
		printf("Rejected\n");
		exit(1);
	}
}


void proc_A1(char *s, int *pos){
	int p = *pos;
	p++;
	char c = s[p];
	if(c == 'b'){
		proc_A1(s, &p);
		*pos = p;
		return;
	}
	else{
		return;
	}
}

void proc_A(char *s, int *pos){
	int p = *pos;
	p++;
	char c = s[p];
	if(c == 'b'){
		proc_A1(s, &p);
		*pos = p;
		return;
	}
	else{
		printf("Rejected\n");
		exit(1);
	}
}

void proc_S( char *s, int *pos){
	int p = *pos;
	p++;
	char c = s[p];
	if(c == 'a'){
		proc_A(s, &p);
		p++; c = s[p];
		if(c == 'c'){
			proc_B(s, &p);
			p++; c = s[p];
			if(c == 'e'){
				*pos = p;
				return;
			}
			else{
				printf("Rejected\n");
			}
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


int main(int argc, char const *argv[])
{
	char *s = (char*)malloc(MAX * sizeof(char));
	printf("Enter the string: ");
	scanf("%s", s);
	int a = -1;
	proc_S(s, &a);
	if(a == strlen(s) - 1){
		printf("Accepted\n");
	}
	return 0;
}