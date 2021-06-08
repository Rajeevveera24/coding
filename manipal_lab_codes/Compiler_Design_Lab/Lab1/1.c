#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	FILE *fa, *fb;
	int ca, cb;
	
	fa = fopen("sampleIn.c", "r");
	if(!fa){
		printf("Cannot open file\n");
		exit(1);
	}
	
	fb = fopen("sampleOut.c", "w");
	
	ca = getc(fa);
	// int count = 0;
	while(ca != EOF){
		if(ca == ' '){
			cb = getc(fa);
			while(cb == ' '){
				cb = getc(fa);
				// printf("%d\t", count++);
			}
			putc(ca, fb);
			putc(cb, fb);
		}
		else if(ca == '\t'){
			putc(' ', fb);
		}
		else{
			putc(ca, fb);
		}
		ca = getc(fa);
	}

	fclose(fa);
	fclose(fb);

	return 0;
}