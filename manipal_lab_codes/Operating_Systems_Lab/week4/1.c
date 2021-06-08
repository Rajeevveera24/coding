#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>

int main(){

	pid_t pid;

	pid = fork();

	if(pid < 0){
		fprintf(stderr,"Fork failed");
		exit(-1);
	}
	else if(pid == 0){
		printf("Child process\n");
	}
	else{
		wait(NULL);
		printf("Child Complete...\n");
		exit(0);
	}
	return 0;
}