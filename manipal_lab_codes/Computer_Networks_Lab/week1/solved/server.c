#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#define PORTNO 10200

int main(int argc, char const *argv[])
{
	int sockfd,newsockfd,portno,clilen,n=1;
	struct sockaddr_in seraddr,cliaddr;
	int i,value;

	// Create an unnamed socket for the server
	sockfd = socket(AF_INET, SOCK_STREAM, 0);

	// Name the socket
	seraddr.sin_family = AF_INET;
	seraddr.sin_port = htons(PORTNO);
	seraddr.sin_addr.s_addr = inet_addr("10.87.2.39");
	bind(sockfd,(struct sockaddr *)
		&seraddr,sizeof(seraddr));

	// Create a connection queue and wait for clients
	listen(sockfd,5);
	// while(1){
		char buf[256];
		printf("Server Waiting\n");
		// Accept a connection
		clilen = sizeof(cliaddr);
		newsockfd = accept(sockfd, 
			(struct sockaddr *)&cliaddr, 
			&clilen);

		// Read and write to client on client_sockfd
		n = read(newsockfd, buf, sizeof(buf));
		printf("\nMessage from client is %s\n", buf);
		n = write(newsockfd, buf, sizeof(buf));
	// }
	return 0;
}