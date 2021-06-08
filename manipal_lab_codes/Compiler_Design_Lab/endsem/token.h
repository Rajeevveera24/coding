typedef struct token
{
	char lexeme_name[50], type[50];
}Token;

bool isNumerical(char c,Token *t,FILE *fp)
{
	fpos_t pos;
	char buf[20];
	int i=0,c1=++col,r1=row;
	buf[i++] = c;
	if(isdigit(c))
	{
		fgetpos(fp,&pos);
		c = getc(fp);
		col++;
		while(isdigit(c))
		{
			buf[i++] = c;
			fgetpos(fp,&pos);
			c = getc(fp);
			col++;
		}
		buf[i] = '\0';
		fsetpos(fp,&pos);
		strcpy(t->lexeme_name,buf);
		strcpy(t->type,"Number");
		return true;
	}
	col--;
	return false;
}

bool isSpecialSymbol(char c,Token *t)
{
	switch(c)
	{
		case ';':strcpy(t->lexeme_name,";");
				 strcpy(t->type,"Semicolon");
				 break;
		case ',':strcpy(t->lexeme_name,",");
				 strcpy(t->type,"Comma");
				 break;
		case '[':strcpy(t->lexeme_name,"[");
				 strcpy(t->type,"LSB");
				 break;
		case ']':strcpy(t->lexeme_name,"]");
				 strcpy(t->type,"RSB");
				 break;
		case '{':strcpy(t->lexeme_name,"{");
				 strcpy(t->type,"LCB");
				 break;
		case '}':strcpy(t->lexeme_name,"}");
				 strcpy(t->type,"RCB");
				 break;
		default :return false;
	}
	return true;
}

bool isIdentOrKeyw(char c,Token *t,FILE *fp)
{
	fpos_t pos;
	char buf[20];
	int i=0,c1=col,r1=row;
	buf[i++] = c;
	if(isalpha(c)!=0 || c=='_')
	{
		fgetpos(fp,&pos);
		c = getc(fp);
		col++;
		while(isalnum(c) || c=='_')
		{
			buf[i++] = c;
			fgetpos(fp,&pos);
			c = getc(fp);
			col++;
		}
		buf[i] = '\0';
		if(strcmp(buf,"public") == 0 || strcmp(buf,"private") == 0 || strcmp(buf,"abstract") == 0 || strcmp(buf,"interface") == 0 || strcmp(buf,"extends") == 0 || strcmp(buf,"static") == 0 || strcmp(buf,"int") == 0 || strcmp(buf,"float") == 0)
			strcpy(t->type,"Keyword");
		else
			strcpy(t->type,"Identifier");
		strcpy(t->lexeme_name,buf);
		fsetpos(fp,&pos);
		strcpy(t->lexeme_name,buf);
		return true;
	}
	return false;
}

Token getNextToken(FILE *fp)
{
	Token t;
	char c = getc(fp);
	while(c==' ' || c=='\t' || c=='\n')
	{
		c = getc(fp);
	}
	if(c==EOF)
	{
		strcpy(t->type,"EOF");
		return t;
	}
	if(isSpecialSymbol(c,&t))
		return t;
	if(isNumerical(c,&t,fp))
		return t;
	if(isIdentOrKeyw(c,&t,fp))
		return t;
	strcpy(t->type,"Invalid");
	return t;
}