#include <stdio.h>
#include "token.h"

int row = 1, col = 0;
struct token * t;

void proc_T(){
	t = getNextToken(&row, &col);
	if(!strcmp(t->lType, "ARITHMETIC OPERATOR")){
		t = getNextToken(&row, &col);
		if(strcmp(t->lType, "NUMERICAL CONSTANT") == 0){
			proc_T();
		}
		else{
			printf("First Error from T\n");
			exit(1);
		}
	}
	else{
		printf("Accepted\n");
		exit(1);
	}
}

void proc_E(){
	t = getNextToken(&row, &col);
	if(strcmp(t->lType, "NUMERICAL CONSTANT") == 0){
		proc_T();
	}
	else{
		printf("Error from E\n");
		exit(1);
	}
	t = getNextToken(&row, &col);
	if(strcmp(t->lType, "SPECIAL SYMBOL") == 0){
		printf("Success\n");
		exit(0);
	}
}


int main(int argc, char const *argv[])
{
	int state, arrSize, numArg, cnt;
	char retType[30], arg[100];
	fa = fopen("sampleIn.c", "r");
	int ca;

	if(!fa){
		printf("Cannot open file\n");
		exit(1);
	}

	removePreDir();
	fclose(fa);
	copyFile();
	removeComment();
	copyFile();

	fa = fopen("temp1.c", "r");
	// fclose(fa);
	proc_E();

	fclose(fa);

	return 0;
}