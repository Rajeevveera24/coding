#include <stdio.h>
#include <string.h>

#define max 100

int Table[256];
char str[max], sub[max], n, m;

void shiftTable(){
	for(int i=0; i<256; i++){
		Table[i] = strlen(sub);
	}
	for(int i=0; i<m-1; i++){
		Table[sub[i]] = m-1-i;
	}
}	

int horspool(){
	shiftTable();
	int k, j, i = m-1;
	while(i < n){
		k = 0;
		while(k<m && sub[m-1-k] == str[i-k]){
			k++;
		}
		if(k == m){
			return i-m+1;
		}
		else{
			i += Table[str[i]];
		}
	}
	return -1;
}

int main(int argc, char const *argv[]){
 	gets(str);
 	gets(sub);
 	m = strlen(sub);
 	n = strlen(str);
 	printf("%d\n", horspool());
 	return 0;
} 