#include <stdio.h>

int main(int argc, char const *argv[])
{
	FILE *fa, *fb;
	int ca, cb;
	
	fa = fopen("sampleIn.txt", "r");
	if(!fa){
		printf("Cannot open file\n");
		exit(1);
	}
	
	fb = fopen("sampleOut.txt", "w");
	
	ca = getc(fa);
	
	while(ca != EOF){
		if(ca == '/'){
			cb = getc(fa);
			if(cb == '/'){
				while(ca != '\n'){
					ca = getc(fa);
				}
			}
			else if(cb == '*'){
				do{
					while(ca != '*'){
						ca = getc(fa);
					}
					ca = getc(fa);
				}while(ca != '/');
			}
			else{
				putc(ca, fb);
				putc(cb, fb);
			}
		}
		putc(ca, fb);
		// getc(ca, fa);
		ca = getc(fa);
	}

	fclose(fa);
	fclose(fb);

	return 0;
}