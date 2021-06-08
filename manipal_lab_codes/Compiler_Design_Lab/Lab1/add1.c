#include <stdio.h>
#include <stdlib.h>

int reverseDigit(int x){
	int rev = 0;
	while(x > 0){
		rev = rev *10 + x %10;
		x /= 10;
	}
	return rev;
}

int main(int argc, char const *argv[])
{
	FILE *fa, *fb;
	int ca, cb, c, line = 1;
	
	fa = fopen("sampleIn.c", "r");
	if(!fa){
		printf("Cannot open file\n");
		exit(1);
	}
	
	fb = fopen("sampleOut.c", "w");
	
	ca = getc(fa);

	while(ca != EOF){
		
		if(ca == EOF){
			break;
		}

		if(ca == '\n'){
			putc(ca, fb);
			if(line < 10){
				putc(line + 48, fb);
				putc('\t', fb);
				putc('\t', fb);
				line++;
			}
			else{
				c = reverseDigit(line);
				while(c > 0){
					cb = c % 10;
					c /= 10;
					putc(cb + 48, fb);
				}
				putc('\t', fb);
				putc('\t', fb);
				line++;
			}
			ca = getc(fa);
			continue;
		}
		putc(ca, fb);
		ca = getc(fa);
	}

	fclose(fa);
	fclose(fb);

	return 0;
}