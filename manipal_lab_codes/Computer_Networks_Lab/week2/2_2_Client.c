#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

void createClientSocket(int *len, int *result, int *sockfd, struct sockaddr_in address) {
	*sockfd = socket(AF_INET,SOCK_STREAM,0);
	address.sin_family = AF_INET;
	address.sin_addr.s_addr = inet_addr("127.0.0.1");
	address.sin_port = htons(10200);
	*len = sizeof(address);
	*result = connect(*sockfd, (struct sockaddr *)&address,*len);
}

void performClientTask(int sockfd) {
	int n = 1;
	char ch[256],buff[256];
	printf("\nEnter String: ");
	gets(ch);
	ch[strlen(ch)] = '\0';
	write(sockfd,ch,strlen(ch));
	printf("\nString from Server is: ");
	while(n) {
		n = read(sockfd,buff,sizeof(buff));
		puts(buff);
	}
}

int main() {
	int len, result, sockfd;
	struct sockaddr_in address;
	createClientSocket(&len,&result,&sockfd,address);
	if(result == -1) {
		perror("\nClient Error.");
		exit(1);
	}
	performClientTask(sockfd);
}
