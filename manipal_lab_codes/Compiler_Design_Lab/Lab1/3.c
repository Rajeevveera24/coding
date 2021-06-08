#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	FILE *fa, *fb;
	
	int ca, cb;
	char *line = NULL;
    size_t len = 0;
    ssize_t read;

	fa = fopen("sampleIn.c", "r");
	if(!fa){
		printf("Cannot open file\n");
		exit(1);
	}
	
	// fb = fopen("sampleOut.c", "w");
	int lineCount = 0;
	while( (read = getline(&line, &len, fa)) != -1){
		lineCount++;
		int i = 0;
		while(i < strlen(line)){
			int j = i;
			if(line[j] == '/' && line[j+1] == '/'){
				break;
			}
			else if(line[j] == '"'){
				do{
					j++;
				}while(line[j] != '"');
				i = j+1;
				continue;
			}
			else if(line[i] == ' '){
				if(line[i+1] == 'i' && line[i+2] == 'n' && line[i+3] == 't' && line[i+4] == ' '){
					printf("INT %d %d\n", lineCount, i+1);
					i += 4;
				}
				else if(line[i+1] == 'w' && line[i+2] == 'h' && line[i+3] == 'i' && line[i+4] == 'l' && line[i+5] == 'e' && line[i+6] == ' '){
					printf("WHILE %d %d\n", lineCount, i+1);
					i += 6;
				}
				else if(line[i+1] == 'c' && line[i+2] == 'h' && line[i+3] == 'a' && line[i+4] == 'r' && line[i+5] == ' '){
					printf("CHAR %d %d\n", lineCount, i+1);
					i += 5;
				}
				else if(line[i+1] == 'r' && line[i+2] == 'e' && line[i+3] == 't' && line[i+4] == 'u' && line[i+5] == 'r' && line[i+6] == 'n' && line[i+7] == ' '){
					printf("RETURN %d %d\n", lineCount, i+1);
					i += 7;
				}
				else{
					i++;
				}
			}
			else{
				i++;
			}
		}
	}

	fclose(fa);
	// fclose(fb);
	return 0;
}
