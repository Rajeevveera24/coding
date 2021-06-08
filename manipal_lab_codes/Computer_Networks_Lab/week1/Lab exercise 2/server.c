#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<time.h>
#define PORTNO 10200

void PerformServerTask(int * newsockfd){
	// Read and write to client_sockfd
	printf("\nSENDING TIME AND PID TO CLIENT\n");
	time_t now = time(0);
	struct tm * time_info = localtime(&now);
	char * time_str = asctime(time_info);
	time_str[strlen(time_str)-1]='\0';
	int pid = getpid();
	char buf[256];
	sprintf(buf, "The server time is %s and the server pid is %d", time_str, pid);
	write(*newsockfd, buf, sizeof(buf));
}

void CreateServerSocket(){
	int sockfd, newsockfd, portno, clilen;
	struct sockaddr_in seraddr,cliaddr;
	int i,value;
	// Create an unnamed socket for the server
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	// Name the socket
	seraddr.sin_family = AF_INET;
	seraddr.sin_addr.s_addr = inet_addr("10.87.2.39");
	seraddr.sin_port = htons(PORTNO);
	bind(sockfd, (struct sockaddr *)&seraddr, sizeof(seraddr));

	// Create a connection queue and wait for clients
	listen(sockfd, 5);

	printf("server waiting");
	// Accept a connection
	clilen = sizeof(clilen);
	newsockfd = accept(sockfd, (struct sockaddr *)&cliaddr,
		&clilen);
	PerformServerTask(&newsockfd);
	close(sockfd);
}

int main(){
	
	CreateServerSocket();

	return 0;
}
