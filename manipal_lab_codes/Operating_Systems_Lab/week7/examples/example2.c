//  message queue example this is the receiver program

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<fcntl.h>
#include<wait.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<sys/shm.h>

// struct msg_structure
// {
// 	long int msg_type ;
// 	char text[500];
// };


// int main()
// {
// 	struct msg_structure msg ;
// 	long int msg_to_rcv = 0 ;
// 	int msgid = msgget((key_t)1234,0666|IPC_CREAT);
// 	if(msgid==-1)
// 	{
// 		printf("Error in message queue creation\n");
// 		exit(1);
// 	}
// 	while(1)
// 	{
// 		if(msgrcv(msgid,(void *)&msg,500,msg_to_rcv,0)==-1)
// 		{
// 			printf("Error in receiving message\n");
// 			exit(1);
// 		}
// 		if(strcmp(msg.text,"q")==0)
// 		{
// 			if(msgctl(msgid,IPC_RMID,0)==-1)
// 			{
// 				printf("Error in deleting message queue\n");
// 				exit(1);
// 			}
// 			exit(0);
// 		}
// 		printf("Message sent is %s\n",msg.text);

// 	}
// }




