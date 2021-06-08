#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/ipc.h>
#include <wait.h>
#include <sys/shm.h>
// #include <sys/message.h>

struct shared_message_st{
	long int type;
	char a[2];
};

int main(int argc, char const *argv[])
{
	struct shared_message_st *shared;
	int shmid = shmget((key_t)1234, sizeof(struct shared_message_st), 0666|IPC_CREAT);
	if(shmid == -1){
		exit(0);
	}
	void *shared_m = shmat(shmid, (void *)0, 0);
	shared = (struct shared_message_st*)shared_m;
	scanf("%c", &shared->a[0]);
	pid_t pid = fork();
	if(pid == 0){
		printf("Child\n");
		shared->a[1] = shared->a[0] + 1;
	}
	else{
		wait(NULL);
		printf("Char from child is %c\n", shared->a[1]);
	}
	return 0;
}