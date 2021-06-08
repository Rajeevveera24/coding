#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <unistd.h>

struct Msg{	
	long int type;
	int num;
};

int main(int argc, char const *argv[])
{
	struct Msg msg;
	int msgid = msgget((key_t)1234, 0666|IPC_CREAT);
	msg.type = 1;
	while(1){
		int res = msgrcv(msgid, (void*)&msg, sizeof(int), msg.type, 0);
		printf("Number received is %d\n", msg.num);
		if(msg.num < 0){
			break;
		}
	}
	msgctl(msgid, IPC_RMID, 0);
	return 0;
}