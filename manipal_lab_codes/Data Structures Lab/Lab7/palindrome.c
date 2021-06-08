#include<stdio.h>
#include"palindrome.h"
int main(){
	dequeue q;
	init(&q);
	char String[30];
	int flag=1;
	printf("Enter the String\n");
	gets(String);
	for(int i=0;i<strlen(String);i++){
		enqueueR(&q,String[i]);
	}
	for(int i=0;i<strlen(String)/2;i++){
		if(dequeueR(&q)!=dequeueF(&q)){
			flag=0;
			break;
		}
	}
	flag?(printf("String is a palindrome\n")):(printf("String is not a palindrome\n"));
	return 0;
}