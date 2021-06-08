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
	
	fb = fopen("sampleOut.c", "w");
	// int comment = 0;
	while( (read = getline(&line, &len, fa)) != -1){
		int i = 0, flag = 0;
		while(i < strlen(line)){
			while(line[i] == ' ' || line[i] == '\t'){
				i++;
			}
			if(line[i] != '#'){
				break;
			}
			flag = 1;
			break;
			// i++;
		}
		if(flag == 0){
			fputs(line, fb);
		}
	}

	fclose(fa);
	fclose(fb);
	return 0;
}
