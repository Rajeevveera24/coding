/*Lex code to count total number of tokens */

%option noyywrap

%{ 
int n = 0 ; 
%} 
%% 

"public"|"private"|"abstract"|"interface"|"extends"|"static"|"final"|"int"|"float"|"boolean" {printf("%s - keyword\n", yytext);}

[a-zA-Z_][a-zA-Z0-9_]* {printf("%s - identifier\n", yytext);} 

[0-9]+("."[0-9]+)* {printf("%s - number\n", yytext);} 

";" {printf("; - Semicolon");} 

"}" {printf("} - Right curly brace\n");} 

"{" {printf("{ - Left curly brace\n");} 

"," {printf(", - Comma\n");} 

"[" {printf("[ - Left square bracket\n");} 

"]" {printf("] - Right square bracket\n");} 
%% 


int main() 

{ 
	yyin = fopen("input_file", "r");
	yylex(); 
	
} 
