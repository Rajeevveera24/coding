#include <stdio.h>
#include <string.h>
#include "token.h"

int row, col;
struct token *t;

void program(int *back);
void decl(int *back);
void datatype(int *back);
void id_list(int *back);
void A(int *back);
void B(int *back);
void stmt_list(int *back);
void stmt(int *back);
void assign_stat(int *back);
void expn(int *back);
void eprime(int *back);
void simple_expn(int *back);
void seprime(int *back);
void term(int *back);
void tprime(int *back);
void factor(int *back);
void decision_stat(int *back);
void dprime(int *back);
void loop_stat(int *back);
void relop(int *back);
void addop(int *back);
void mulop(int *back);
void error();
void checkNull( struct token *tok);

void checkNull(struct token *tok){
	if(tok == NULL){
		printf("End of File Found\n");
		exit(2);
	}
}

void error(){
	printf("Error in input file\n");
	printf("Current token is %s in row %d and column %d\n",t->lName, row, col);
	exit(1);
}

int main(int argc, char const *argv[])
{
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

	// struct token *t, *t_temp_1, *t_temp_2, *t_temp_3, *t_temp_4;
	// struct token * t;

	fa = fopen("temp1.c", "r");

	row = 1; col = 0;

	// t = (getNextToken(&row, &col));

	program(0);

	fclose(fa);

	return 0;
}

void program(int *back){

	printf("program\n");

	t = getNextToken(&row, &col);
	checkNull(t);

	if(strcmp(t->lName, "main") == 0){
		
		t = getNextToken(&row, &col);
		checkNull(t);

		if(strcmp(t->lName, "(") == 0){
			
			t = getNextToken(&row, &col);
			checkNull(t);
			
			if(strcmp(t->lName, ")") == 0){
			
				t = getNextToken(&row, &col);
				checkNull(t);

				if(strcmp(t->lName, "{") == 0){

					int b = 0;
					
					decl(&b);
					stmt_list(&b);
					
					if(b == 0){
						t = getNextToken(&row, &col);
						// printToken(t);
						checkNull(t);
					}

					if(strcmp(t->lName, "}") == 0){
						printf("Program has no syntactic errors\n");
						return;
					}
					else{
						printf("here from program\n");
						error();
					}
				}
				else{
					error();
				}

			}
			else{
				error();
			}
		}
		else{
			error();
		}
	}
	else{
		printf("Error: Main NOT Found\n");
		exit(1);
	}
}

void decl(int *back){
	printf("declarations\n");
	
	int b = *back;

	if(b == 0){
		t = getNextToken(&row, &col);
		checkNull(t);
	}

	if(!strcmp(t->lName, "int") || !strcmp(t->lName, "char")){
		
		b = 1;
		
		datatype(&b);
		id_list(&b);
		
		if(b == 0){
			t = getNextToken(&row, &col);
			checkNull(t);
		}

		if(strcmp(t->lName, ";") == 0){
			b = 0;
			decl(&b);
			*back = b; return;
		}
		else{
			error();
		}
	}
	else{
		b = 1;
		*back = b; return;
	}
}

void datatype(int *back){
	printf("datatype\n");
	int b = *back;

	if(b == 0){
		t = getNextToken(&row, &col);
		checkNull(t);
	}

	if(!strcmp(t->lName, "int") || !strcmp(t->lName, "char")){
		b = 0;
		*back = b; return;
	}
	else{
		error();
	}
}

void id_list(int *back){
	printf("Identifier list\n");
	
	int b = *back;

	if(b == 0){
		t = getNextToken(&row, &col);
		checkNull(t);
	}

	if(strcmp(t->lType, "IDENTIFIER") == 0){
		b = 0;
		A(&b);
		*back = b; return;
	}
	else{
		error();
	}
}

void A(int *back){
	printf("A\n");

	int b = *back;
	if(b == 0){
		t = getNextToken(&row, &col);
		checkNull(t);
	}
	if(!strcmp(t->lName, ",")){
		b = 0;
		id_list(&b);
		*back = b; return;
	}
	else if(!strcmp(t->lName, "[")){
		
		t = getNextToken(&row, &col);
		checkNull(t);

		if(!strcmp(t->lType, "NUMERICAL CONSTANT")){

			t = getNextToken(&row, &col); checkNull(t);

			if(!strcmp(t->lName, "]")){
				b = 0;
				B(&b);
				*back = b; return;
			}
			else{
				error();
			}
		}	
		else{
			error();
		}
	}
	else{
		b = 1;
		*back = b; return;
	}
}

void B(int *back){
	printf("B\n");

	int b = *back;
	
	if(b == 0){
		t = getNextToken(&row, &col);
		checkNull(t);
	}		

	if(!strcmp(t->lName, ",")){
		b = 0;
		id_list(&b);
		*back = b; return;
	}
	else{
		b = 1;
		*back = b; return;
	}
}

void stmt_list(int *back){
	printf("statement list\n");

	int b = *back;

	if(b == 0){
		t = getNextToken(&row, &col);
		// printToken(t);
		checkNull(t);
	}

	if(!strcmp(t->lType, "IDENTIFIER") || !strcmp(t->lName, "if") || !strcmp(t->lName, "while") || !strcmp(t->lName, "for") || !strcmp(t->lName, "do")){
		b = 1;
		stmt(&b);
		stmt_list(&b);
		*back = b; return;
	}
	else{
		b = 1;
		*back = b; return;
	}	
}

void stmt(int *back){
	printf("statement\n");
	
	int b = *back;

	if(b == 0){
		t = getNextToken(&row, &col);
		checkNull(t);
	}

	if(!strcmp(t->lType, "IDENTIFIER")){
		b = 1;
		assign_stat(&b);
		if(b == 0){
			t = getNextToken(&row, &col);
			checkNull(t);
		}
		if(!strcmp(t->lName, ";")){
			b = 0;
			*back = b; return;
		}
		else{
			error();
		}
	}
	else if(!strcmp(t->lName, "if")){
		b = 1;
		decision_stat(&b);
		*back = b; return;
	}
	else if(!strcmp(t->lName, "while") || !strcmp(t->lName, "for") || !strcmp(t->lName, "do")){
		b = 1;
		loop_stat(&b);
		*back = b; return;
	}
	else{
		error();
	}
}

void assign_stat(int *back){
	printf("assignment statement\n");

	int b = *back;

	if(b == 0){
		t = getNextToken(&row, &col);
		checkNull(t);
	}

	if(!strcmp(t->lType, "IDENTIFIER")){
		t = getNextToken(&row, &col); checkNull(t);
		if(!strcmp(t->lName, "=")){
			// t = getNextToken(&row, &col); checkNull(t);
			b = 0;
			expn(&b);
			*back = b; return;
		}
		else{
			printf("Error from assignment 1\n");
			error();
		}
	}
	else{
		printf("Error from assignment 2\n");
		error();
	}

}

void expn(int *back){
	printf("Expression\n");

	int b = *back;

	simple_expn(&b);
	eprime(&b);

	*back = b; return;
}

void eprime(int *back){
	printf("eprime\n");
	
	int b = *back;
	if(b == 0){
		t = getNextToken(&row, &col);
		checkNull(t);
	}
	if(!strcmp(t->lType, "RELATIONAL OPERATOR")){
		b = 1;
		relop(&b);
		simple_expn(&b);
		*back = b; return;
	}
	else{
		b = 1;
		*back = b; return;
	}
}

void simple_expn(int *back){
	printf("Simple Expression\n");

	int b = *back;

	term(&b);
	seprime(&b);

	*back = b; return;
}

void seprime(int *back){
	printf("Seprime\n");

	int b = *back;
	if(b == 0){
		t = getNextToken(&row, &col);
		checkNull(t);
	}
	if(!strcmp(t->lName, "+") || !strcmp(t->lName, "-")){
		b = 1;
		addop(&b);
		term(&b);
		seprime(&b);
		*back = b; return;
	}
	else{
		b = 1;
		*back = b; return;
	}
}

void term(int *back){
	printf("Term\n");

	int b = *back;

	factor(&b);
	tprime(&b);

	*back = b; return;
}

void tprime(int *back){
	printf("Tprime\n");

	int b = *back;
	if(b == 0){
		t = getNextToken(&row, &col);
		checkNull(t);
	}
	if(!strcmp(t->lName, "*") || !strcmp(t->lName, "/") || !strcmp(t->lName, "%")){
		b = 1;
		mulop(&b);
		factor(&b);
		tprime(&b);
		*back = b; return;
	}
	else{
		b = 1;
		*back = b; return;
	}
}

void factor(int *back){
	printf("Factor\n");
				
	int b = *back;

	if(b == 0){
		t = getNextToken(&row, &col);
		checkNull(t);
	}

	if(!strcmp(t->lType, "NUMERICAL CONSTANT") || !strcmp(t->lType, "IDENTIFIER")){
		b = 0;
		*back = b; return;
	}
	else{
		printf("Error from factor\n");
		error();
	}
}

void decision_stat(int *back){
	printf("Decision Statement\n");

	int b = *back;
	if(b == 0){
		t = getNextToken(&row, &col); checkNull(t);
	}
	if(!strcmp(t->lName, "if")){
		t = getNextToken(&row, &col); checkNull(t);
		if(!strcmp(t->lName, "(")){
			// t = getNextToken(&row, &col); checkNull(t);
			b = 0;
			expn(&b);
			if(b == 0){
				t = getNextToken(&row, &col); checkNull(t);
			}
			if(!strcmp(t->lName, ")")){
				t = getNextToken(&row, &col); checkNull(t);
				if(!strcmp(t->lName, "{")){
					b = 0;
					stmt_list(&b);
					if(b == 0){
						t = getNextToken(&row, &col); checkNull(t);
					}
					if(!strcmp(t->lName, "}")){
						b = 0;
						dprime(&b);
						*back = b; return;
					}
					else{
						error();
					}
				}
				else{
					error();
				}
			}
			else{
				error();
			}
		}
		else{
			error();
		}
	}
	else{
		error();
	}
}

void dprime(int *back){
	printf("Deprime\n");

	int b = *back;
	if(b == 0){
		t = getNextToken(&row, &col); checkNull(t);
	}
	if(!strcmp(t->lName, "else")){
		t = getNextToken(&row, &col); checkNull(t);
		if(!strcmp(t->lName, "{")){
			// t = getNextToken(&row, &col); checkNull(t);
			b = 0;
			stmt_list(&b);
			if(b == 0){
				t = getNextToken(&row, &col); checkNull(t);
			}

			if(!strcmp(t->lName, "}")){
				b = 0;
				*back = b; return;
			}
			else{
				error();
			}
		}
		else{
			error();
		}
	}
	else{
		b = 1;
		*back = b; return;
	}	
}

void loop_stat(int *back){
	printf("Looping Statement\n");

	int b = *back;
	if(b == 0){
		t = getNextToken(&row, &col); checkNull(t);
	}
	if(!strcmp(t->lName, "while")){
		t = getNextToken(&row, &col); checkNull(t);
		if(!strcmp(t->lName, "(")){
			b = 0;
			expn(&b);
			if(b == 0){
				t = getNextToken(&row, &col); checkNull(t);
			}
			if(!strcmp(t->lName, ")")){
				t = getNextToken(&row, &col); checkNull(t);
				if(!strcmp(t->lName, "{")){
					b = 0;
					stmt_list(&b);
					if(b == 0){
						t = getNextToken(&row, &col); checkNull(t);
					}
					if(!strcmp(t->lName, "}")){
						b = 0;
						*back = b; return;
					}
					else{
						error();
					}
				}
				else{
					error();
				}
			}
			else{
				error();
			}
		}
		else{
			error();
		}
	}
	else if(!strcmp(t->lName, "for")){
		t = getNextToken(&row, &col); checkNull(t);
		if(!strcmp(t->lName, "(")){
			b = 0;
			assign_stat(&b);
			if(b == 0){
				t = getNextToken(&row, &col); checkNull(t);
			}
			if(!strcmp(t->lName, ";")){
				b = 0;
				expn(&b);
				if(b == 0){
					t = getNextToken(&row, &col); return;
				}
				if(!strcmp(t->lName, ";")){
					b = 0;
					assign_stat(&b);
					if(b == 0){
						t = getNextToken(&row, &col); checkNull(t);
					}
					if(!strcmp(t->lName, ")")){
						t = getNextToken(&row, &col); checkNull(t);
						if(!strcmp(t->lName, "{")){
							b = 0;
							stmt_list(&b);
							if(b == 0){
								t = getNextToken(&row, &col); checkNull(t);
							}
							if(!strcmp(t->lName, "}")){
								b = 0;
								*back = b; return;
							}
							else{
								error();
							}
						}
						else{
							error();
						}
					}
					else{
						error();
					}
				}
				else{
					error();
				}
			}
			else{
				error();
			}
		}
		else{
			error();
		}
	}
	else if(!strcmp(t->lName, "do")){
		t = getNextToken(&row, &col); checkNull(t);
		if(!strcmp(t->lName, "{")){
			b = 0;
			stmt_list(&b);
			if(b == 0){
				t = getNextToken(&row, &col); checkNull(t);
			}
			if(!strcmp(t->lName, "}")){
				t = getNextToken(&row, &col); checkNull(t);
				if(!strcmp(t->lName, "while")){
					t = getNextToken(&row, &col);
					if(!strcmp(t->lName, "(")){
						b = 0;
						expn(&b);
						if(b == 0){
							t = getNextToken(&row, &col); checkNull(t);
						}
						if(!strcmp(t->lName, ")")){
							t = getNextToken(&row, &col); checkNull(t);
							if(!strcmp(t->lName, ";")){
								b = 0;
								*back = b; return;
							}
							else{
								error();
							}
						}
						else{
							error();
						}
					}
					else{
						error();
					}
				}else{
					error();
				}
			}else{
				error();
			}
		}else{
			error();
		}
	}
	else{
		error();
	}
}

void relop(int *back){
	printf("Relational Operator\n");
			
	int b = *back;

	if(b == 0){
		t = getNextToken(&row, &col);
		checkNull(t);
	}

	if(!strcmp(t->lType, "RELATIONAL OPERATOR")){
		b = 0;
		*back = b; return;
	}
	else{
		error();
	}	
}

void addop(int *back){
	printf("Addition Operator\n");
		
	int b = *back;

	if(b == 0){
		t = getNextToken(&row, &col);
		checkNull(t);
	}

	if(!strcmp(t->lName, "+") || !strcmp(t->lName, "-")){
		b = 0;
		*back = b; return;
	}
	else{
		error();
	}
}

void mulop(int *back){
	printf("Multiplication Operator\n");

	int b = *back;

	if(b == 0){
		t = getNextToken(&row, &col);
		checkNull(t);
	}

	if(!strcmp(t->lName, "*") || !strcmp(t->lName, "/") || !strcmp(t->lName, "%")){
		b = 0;
		*back = b; return;
	}
	else{
		error();
	}
}