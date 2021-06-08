#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include <stdlib.h>
#include <unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>

#define PORTNO 10200

void createServerSocket(int *s_sockfd, struct sockaddr_in server_addr){
	
	*s_sockfd = socket(AF_INET, SOCK_STREAM, 0);

	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(PORTNO);
	server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

	bind(*s_sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));

	listen(*s_sockfd, 5);
}

void performServerTask(int  c_sockfd, struct sockaddr_in client_addr){
	char str[80];
	int n;
	while(1){
		n = read(c_sockfd, str, sizeof(str));
		printf("\nString sent by client is: ");
		puts(str);
		printf("\nClient IP is %d and port number is %d\n",client_addr.sin_addr.s_addr, client_addr.sin_port);

		for(int i=0;i<strlen(str);i++){
			str[i] = toupper(str[i]);
		}
		printf("String sent back to client is: ");
		puts(str);
		write(c_sockfd, str, sizeof(str));

		if(strcmp(str,"QUIT") == 0){
			printf("Closing connection...\n\n");
			close(c_sockfd);
			return;
		}
	}
}

int main(){
	int s_sockfd, c_sockfd, clilen;
	struct sockaddr_in server_addr, client_addr;

	createServerSocket(&s_sockfd, server_addr);

	clilen = sizeof(client_addr);
	c_sockfd = accept(s_sockfd,(struct sockaddr *)&client_addr, &clilen);

	performServerTask(c_sockfd, client_addr);
	close(s_sockfd);
	return 0;
}