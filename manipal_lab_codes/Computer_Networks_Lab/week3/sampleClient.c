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
	char buf1[25], buf2[25];
	struct sockaddr_in address;

	sd = socket(AF_INET, SOCK_DGRAM, 0);

	address.sin_family = AF_INET;
	address.sin_addr.s_addr = inet_addr("127.0.0.1");
	address.sin_port = htons(9704);

	printf("Enter message:\t");
	gets(buf1);

	int len = sizeof(address);

	int m = sendto(sd, buf1, sizeof(buf1), 0, (struct sockaddr* )&address, len);

	int n = recvfrom(sd, buf2, sizeof(buf2), 0, (struct sockaddr* )&address, &len);

	printf("The server echoes back: ");
	puts(buf2);

	return 0;
}