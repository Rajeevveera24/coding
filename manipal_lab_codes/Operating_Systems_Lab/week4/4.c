#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>


int main(){

	pid_t pid = fork();
	
	if(pid>0){
		sleep(50);
	}
	else if(pid==0){
		exit(0);
	}
	else{
		printf("Cannot create child process \n");
	}

	return 0;
}