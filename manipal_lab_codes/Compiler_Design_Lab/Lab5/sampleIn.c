#include <stdio.h>
#include <stdio.h>
#include <string.h>
#include "token.h"

// int row, col;
// struct token *t;

// void program(int back);
// void decl(int back);
// void datatype(int back);
// void id_list(int back);
// void A(int back);
// void B(int back);
// void stmt_list(int back);
// void stmt(int back);
// void assign_stat(int back);
// void expn(int back);
// void eprime(int back);
// void simple_expn(int back);
// void seprime(int back);
// void term(int back);
// void tprime(int back);
// void factor(int back);
// void decision_stat(int back);
// void dprime(int back);
// void loop_stat(int back);
// void relop(int back);
// void addop(int back);
// void mulop(int back);

main()
{
	int a;
	int b;
	a = 5;
	b = 7;

	a = a + b;
	b = b - a;

	while(b < 5){
		a = a + b;
		b = b + 1;
	}	

	if(a > b){
		a = a + 1;
	}

	for(i = 5; i < 6; i = i + 1){
		a = a + b;
	}

	do{
		a = a + 65;
		d = a * b;
	}while( );
}