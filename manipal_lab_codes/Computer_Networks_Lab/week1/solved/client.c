#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <arpa/inet.h>

int main(int argc, char const *argv[])
{
	struct sockaddr_in address;
	// Create socket for client
	int sockfd = socket(AF_INET, SOCK_STREAM, 0);
	// Name the socket as agreed with the server
	address.sin_family = AF_INET;
	address.sin_port = htons(10200);
	address.sin_addr.s_addr = inet_addr("10.87.2.39");

	// Connect your socket to the server's socket
	int status = connect(sockfd,
		(struct sockaddr *)&address, sizeof(address));
	if(status == -1){
		perror("\nClient error");
		exit(1);
	}

	// You can now read and write via sockfd
	char ch[256],buf[256];
	while(1){
		printf("Enter a string\n");
		gets(ch);
		ch[strlen(ch)] = '\0';
		write(sockfd, ch, strlen(ch));
		printf("STring sent back from server is ...\n");
		read(sockfd, buf, sizeof(buf));
		puts(buf);
	}
	return 0;
}