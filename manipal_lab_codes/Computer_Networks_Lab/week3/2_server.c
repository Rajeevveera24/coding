#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
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

	int sfd = socket(AF_INET, SOCK_DGRAM, 0);

	struct sockaddr_in s_addr, c_addr;
	s_addr.sin_family = AF_INET;
	s_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	s_addr.sin_port = htons(10200);

	bind(sfd, (struct sockaddr *)&s_addr, sizeof(s_addr));

	recvfrom(sfd, &message, sizeof(message), 0, (struct sockaddr*)&c_addr, sizeof(c_addr));
	message.status = 101;
	strcpy(message.phrase, "OK");
	sendto(sfd, &message, sizeof(message), 0, (struct sockaddr*)&c_addr, sizeof(c_addr));
	close(sfd);
	return 0;
}