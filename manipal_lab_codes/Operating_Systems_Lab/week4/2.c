#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
	int status;
	pid_t pid;

	pid=fork();
	
	if(pid==-1){
		printf("ERROR\nChild not created\n");
	}
	else if(pid==0){
		printf("Child process of program 2 in execution\n");
		execvp("./1",NULL);
		exit(0);
	}
	else{
		wait(&status);
		printf("Parent process of program 2...\n");
		printf("Child returned %d ...\n",status);
	}

	return 0;
}