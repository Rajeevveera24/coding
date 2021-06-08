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
// int main()
// {
// 	char sentence[] = "My name is yash";
// 	int fd[2];
// 	char buffer[50];
// 	pipe(fd);
// 	write(fd[1],sentence,sizeof(sentence));
// 	read(fd[0],buffer,sizeof(buffer));
// 	printf("%s",buffer);
// }

// int main()
// {
// 	pid_t pid ;
// 	int fd[2];
// 	pipe(fd);
// 	pid = fork();
// 	if(pid==0)
// 	{
// 		printf("Entering child\n");
// 		close(fd[1]);
// 		char buffer[100];
// 		read(fd[0],buffer,sizeof(buffer));
// 		printf("Message from parent received\n");
// 		printf("%s\n",buffer);
// 		printf("Ending child now\n");

// 	}
// 	else
// 	{
// 		close(fd[0]);
// 		//sleep(5);
// 		char message[] = "hello world" ;
// 		write(fd[1],message,sizeof(message));
// 		printf("Parent has sent message to child\n");
// 		wait(NULL);
// 	}
// }


//  message queue example sender program
// struct msg_structure
// {
// 	long int msg_type ;
// 	char text[500];
// };

// int main()
// {
// 	struct msg_structure msg ;
// 	int msgid ;
// 	char buffer[100];
// 	msgid = msgget((key_t)1234,0666|IPC_CREAT);
// 	if(msgid==-1)
// 	{
// 		printf("There is an error in message queue creation\n");
// 		exit(1);
// 	}
// 	while(1)
// 	{
// 		printf("Enter some text or q to exit\n");
// 		gets(buffer);
		
// 		msg.msg_type = 1 ;
// 		strcpy(msg.text,buffer);
// 		if((msgsnd(msgid,(void*)&msg,500,0))==-1)
// 		{
// 			printf("There is an error in sending message to queue\n");
// 			exit(1);
// 		}
// 		if(strcmp(buffer,"q")==0)
// 		{
// 			exit(0);
// 		}
// 	}
// }





