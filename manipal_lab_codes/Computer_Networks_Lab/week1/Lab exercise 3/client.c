#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>

#define PORT 10200

void CreateClientSocket(int *sockfd, struct sockaddr_in s_address, int * len, int *result){
	*sockfd = socket(AF_INET, SOCK_STREAM, 0);

	s_address.sin_port = htons(PORT);
	s_address.sin_addr.s_addr = inet_addr("127.0.0.1");
	s_address.sin_family = AF_INET;

	*len = sizeof(s_address);

	*result = connect(*sockfd,(struct sockaddr *)&s_address, *len);
}

void PerformClientTask(int sockfd){
	char str[80];
	int n = 1;
	while(1){
		printf("Enter string to be sent to server:\t");
		gets(str);
		write(sockfd, str, sizeof(str));
		n = read(sockfd, str, sizeof(str));

		printf("String returned by server is ");
		puts(str);

		if(strcmp(str,"QUIT") == 0){
			printf("Closing connection...\n\n");
			close(sockfd);
			return;
		}
	}
}

int main(){
	int len, result, sockfd;
	struct sockaddr_in s_address;

	CreateClientSocket(&sockfd, s_address, &len, &result);

	if(result == -1){
		printf("Client error...\n\n");
		exit(1);
	}

	PerformClientTask(sockfd);

	return 0;
}