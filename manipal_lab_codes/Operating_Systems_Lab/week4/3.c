#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>

int main(){
    int status;

    printf("Parent process\n");
    pid_t pid = fork();

    if(pid == -1){
        printf("Error\n");
    }
    else if (pid == 0){
        printf("Parent ID:%d\n", (int)getpid);
        printf("Child ID:%d\n", getpid());
        printf("Child process completed\n");
        exit(0);
    }
    else{
    	// printf("Parent ID:%d\n", pid);
        wait(&status);
        printf("Child completed with status %d\n",status);
    }
    return 0;
}