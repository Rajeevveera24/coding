#include <stdio.h>
#include<string.h>
#include"circq.h"
int main(){
	char str[30];
	int size;
	printf("Enter the size of the queue\n");
	scanf("%d",&size);
	cirque cq;
	init_cq(&cq,size);
	int option = 1;
	do{
		printf("Enter 1,2,3,0 to add,delete,display and exit respectively:\t");
		scanf("%d",&option);
		if(option==1){
			printf("Enter the string to be inserted:\t");
			scanf("%s",str);
			insertcq(&cq,str);
		}
		else if(option==2){
			(deletecq(&cq));
		}
		else if(option==3){
			displaycq(&cq);
		}
		else{
			break;
		}
	}
	while(option!=0);
	return 0;
}