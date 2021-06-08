#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/msg.h>
#include <sys/ipc.h>
#include <unistd.h>
#include <fcntl.h>

struct Msg{
	long int type;
	int num;
};

int main(int argc, char const *argv[])
{
	struct Msg msg;
	msg.type = 1;
	int msgid = msgget((key_t)1234, 0666|IPC_CREAT);
	while(1){
		scanf("%d", &msg.num);
		int res = msgsnd(msgid, (void*)&msg, sizeof(int), 0);
		printf("Sent\n");
		if(msg.num < 0){
			break;
		}
	}
	msgctl(msgid, IPC_RMID, 0);
	return 0;
}