#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
// #include <fnctl.h>

int sfd;
struct sockaddr_in saddr;

void createClientSocket(){
	sfd = socket(AF_INET, SOCK_STREAM, 0);
	saddr.sin_port = htons(10200);
	saddr.sin_family = AF_INET;
	saddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	// bind(sfd, (struct sockaddr*)&saddr, sizeof(saddr));
}

void performClientTask(){
	int n, res = connect(sfd, (struct sockaddr*)&saddr, sizeof(saddr));
	if(res == -1){
		printf("Error\n");
		exit(1);
	}
	char str[80];
	printf("Enter string:\t");
	gets(str);
	str[strlen(str)] = '\0';
	write(sfd, str, sizeof(str));
	printf("String from server is: ");
	while(n){
		n = read(sfd, str, sizeof(str));
		puts(str);
	}
}

int main(int argc, char const *argv[])
{
	createClientSocket();
	performClientTask();
	close(sfd);
	return 0;
}