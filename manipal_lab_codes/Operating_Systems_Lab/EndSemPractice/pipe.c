#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define MAX 20

int main(int argc, char const *argv[])
{
	int fd[2];
	int num = 0,  num1;
	int p = pipe(fd);
	if(p == -1){
		printf("Failed to create pipe\n");
		exit(0);
	}
	pid_t pid = fork();
	while(1){
		if(pid < 0){
			printf("Fork failed\n");
		}
		else if(pid == 0){
			num++;
			num%=MAX;
			printf("Child Writes %d\n", num);
			write(fd[1], &num, sizeof(num));
			sleep(1);
		}
		else{
			read(fd[0], &num1, sizeof(num1));
			printf("Parent reads %d\n", num1);
			sleep(2);
		}
	}
	return 0;
}