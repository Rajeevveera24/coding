#include <stdio.h>
#include <stdlib.h>
// #include "token.h"
#include <string.h>

#define MAX 80

void proc_S(char *, int *);
void proc_T(char *, int *);
void proc_T1(char *, int *);

void proc_T1(char *s, int *pos){
	printf("T1\t");
	int p = *pos;
	p++;
	char c = s[p];
	if(c == ','){
		proc_S(s, &p);
		proc_T1(s, &p);
		*pos = p;
		return;
	}
	else {//if(c == '$'){
		// *pos = p-1;
		return;
	}
	// else{
	// 	printf("Rejected\n");
	// 	exit(1);
	// }
}

void proc_T(char *s, int *pos){
	printf("T\t");
	int p = *pos;
	// char c = s[p];
	proc_S(s, &p);
	proc_T1(s, &p);
	*pos = p;
	return;
}

void proc_S( char *s, int *pos){
	printf("S\t");
	int p = *pos;
	p++;
	char c = s[p];
	if(c == 'a' || c == '>'){
		*pos = p;
		return;
	}
	else if(c == '('){
		proc_T(s, &p);
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


int main(int argc, char const *argv[])
{

	char *s = (char*)malloc(MAX * sizeof(char));
	printf("Enter the string: ");
	scanf("%s", s);
	int a = -1;
	proc_S(s, &a);
	// printf("%d\n", a);
	if(a == strlen(s) - 1){
		printf("\nAccepted\n");
	}
	return 0;
}