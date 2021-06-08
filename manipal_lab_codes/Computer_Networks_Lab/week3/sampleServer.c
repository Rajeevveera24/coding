#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include<unistd.h>

int main(){
	int sd;
	char buf[25];
	struct sockaddr_in sadd, cadd;

	sd = socket(AF_INET, SOCK_DGRAM, 0);

	sadd.sin_family = AF_INET;
	sadd.sin_addr.s_addr = inet_addr("127.0.0.1");
	sadd.sin_port = htons(9704);

	int result = bind(sd, (struct sockaddr *)&sadd, sizeof(sadd));
	int len = sizeof(cadd);

	int m = recvfrom(sd, buf, sizeof(buf), 0, (struct sockaddr *)&cadd, &len);

	printf("The server sends: ");
	puts(buf);

	int n = sendto(sd, buf, sizeof(buf), 0, (struct sockaddr *)&cadd, len);

	return 0;
}