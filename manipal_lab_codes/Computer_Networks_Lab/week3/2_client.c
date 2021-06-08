#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>

struct header_line{
	char header_name[80];
	int value;
};

struct http_message{
	char method[10], url[80], body[20][80], phrase[10];
	unsigned int status;
	float version;
	struct header_line header;
};

int main(){

	struct http_message message;
	strcpy(message.method,"GET");
	strcpy(message.url,"www.cn.com");
	message.version = 5.1;
	strcpy(message.header.header_name,"Header#1");
	message.header.value = 100;
	strcpy(message.body[0], "Hello");
	strcpy(message.body[1], "How are you?");

	int cfd = socket(AF_INET, SOCK_DGRAM, 0);

	struct sockaddr_in caddr;

	caddr.sin_family = AF_INET;
	caddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	caddr.sin_port = htons(10200);

	int len = sizeof(caddr);

	sendto(cfd, &message, sizeof(message), 0, (struct sockaddr*)&caddr, len);

	printf("Request sent...\n\n");

	recvfrom(cfd, &message, sizeof(message), 0, (struct sockaddr*)&caddr, &len);
	printf("Response received is...\n");
	printf("status Line: %f %d %s\n",message.version, message.status, message.phrase);
	printf("Header Line: %s: %d", message.header.header_name,message.header.value);
	printf("\n");
	printf("Body:\n");
	printf("\t%s\n",message.body[0]);
	printf("\t%s\n",message.body[1]);

	close(cfd);
	return 0;
}