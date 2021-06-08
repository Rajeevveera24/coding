#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#define PORTNO 10200

void createServerSocket(int *sockfd, int *newsockfd, int *portno, struct sockaddr_in seraddr) {
	*sockfd = socket(AF_INET,SOCK_STREAM,0);
	seraddr.sin_family = AF_INET;
	seraddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	seraddr.sin_port = htons(PORTNO);
	bind(*sockfd, (struct sockaddr *)&seraddr,sizeof(seraddr));
	listen(*sockfd, 5);
}

void performServerTask(int sockfd, int newsockfd, struct sockaddr_in cliaddr) {
	int clilen, n = 1;
	int x[2], y = 0;
	char op;
	while(1) {
		clilen = sizeof(clilen);
		newsockfd = accept(sockfd, (struct sockaddr *)&cliaddr,&clilen);
		if(fork() == 0) {
			n = read(newsockfd,&op,sizeof(char));
			n = read(newsockfd,&x,2*sizeof(int));
			printf("\nMessage from Client: %d %c %d",x[0],op,x[1]);
			switch(op) {
				case '+':	y = x[0] + x[1];
							break;
				case '-':	y = x[0] - x[1];
							break;
				case '*':	y = x[0] * x[1];
							break;
				case '/':	y = x[0] / x[1];
							break;
			}
			n = write(newsockfd,&y,sizeof(int));
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