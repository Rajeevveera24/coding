#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#define PORTNO 10200

void sort(int list[], int n) { 
	int c, d, t; 
	for (c = 0; c < (n - 1); c++)
		for (d = 0; d < n - c - 1; d++)
			if (list[d] > list[d + 1]) { 
				t = list[d]; 
				list[d] = list[d + 1]; 
				list[d + 1] = t; 
			}
}

void createServerSocket(int *sockfd, int *newsockfd, int *portno, struct sockaddr_in seraddr) {
	*sockfd = socket(AF_INET,SOCK_STREAM,0);
	seraddr.sin_family = AF_INET;
	seraddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	seraddr.sin_port = htons(PORTNO);
	bind(*sockfd, (struct sockaddr *)&seraddr,sizeof(seraddr));
	listen(*sockfd, 5);
}

void performServerTask(int sockfd, int newsockfd, struct sockaddr_in cliaddr) {
	int message[10];
	int clilen, n = 1;
	int x = 0;
	while(1) {
		clilen = sizeof(clilen);
		newsockfd = accept(sockfd, (struct sockaddr *)&cliaddr,&clilen);
		if(fork() == 0) {
			n = read(newsockfd,&x,sizeof(int));
			n = read(newsockfd,&message,x*sizeof(int));
			printf("\nMessage from Client: ");
			for (int i = 0; i < x; ++i)
				printf("%d ",message[i]);
			int pid = getpid();
			printf("\nPID Value: %d\n",pid);
			sort(message,x);
			n = write(newsockfd,&message,x*sizeof(int));
			n = write(newsockfd,&pid,sizeof(int));
			close(newsockfd);
			exit(0);
		}
		else
			close(newsockfd);
	}
}

int main() {
	int sockfd, newsockfd, portno;
	struct sockaddr_in seraddr, cliaddr;
	createServerSocket(&sockfd,&newsockfd,&portno,seraddr);
	performServerTask(sockfd,newsockfd,cliaddr);
}