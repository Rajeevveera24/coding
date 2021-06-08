#include <stdio.h>
#include <string.h>

int substringIndex(char *str, char *sub);

int main(){
	char str[80], sub[80];
	
	printf("Enter the main string:\t");
	gets(str);
	str[strlen(str)] = '.';
	printf("Enter the substring to be searched for:\t");
	gets(sub);

	int index = substringIndex(str,sub);

	if(index == -1){
		printf("substring not found in main string.\n");
	}
	else{
		printf("Substring found starting in position %d of main string.\n",index);
	}

	return 0;
}

int substringIndex(char* str, char* sub){

	int i,j;

	for(int i=0; i<(strlen(str) - strlen(sub)); i++){
		j = 0;

		while(sub[j] == str[i+j]){
			j++;
		}
		if(j == strlen(sub)){
			return (i+1);
		}
	}
	return -1;
}