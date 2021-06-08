#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <netinet/in.h>
#include <unistd.h>
#include <arpa/inet.h>

int sfd, cfd, slen, clen;

struct sockaddr_in saddr, caddr;

void createServeSocket(){
	sfd = socket(AF_INET, SOCK_STREAM, 0);
	saddr.sin_port = htons(10200);
	saddr.sin_family = AF_INET;
	saddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	int res = bind(sfd, (struct sockaddr*)&saddr, sizeof(saddr));
	listen(sfd, 5);
}

void performServerTask(){
	int result, nread, fd;
	fd_set readfds, testfds;
	FD_ZERO(&readfds);
	FD_SET(sfd, &readfds);
	while(1){
		char ch[80];
		int fd, nread;
		testfds = readfds;
		printf("Server Waiting!\n");
		result = select(FD_SETSIZE, &testfds, (fd_set*)0, (fd_set*)0, (struct timeval*)0);
		if(result < 1){
			printf("Error\n");
			exit(1);
		}
		for(fd = 0; fd<FD_SETSIZE; fd++){
			if(FD_ISSET(fd, &testfds))
				if(fd == sfd){
					clen = sizeof(caddr);
					cfd = accept(sfd, (struct sockaddr*)&caddr, &clen);
					FD_SET(cfd, &readfds);
					printf("Adding client on %d\n", cfd);
				}
				else{
					ioctl(fd, FIONREAD, &nread);
					if(nread == 0){
						close(fd);
						FD_CLR(fd, &readfds);
						printf("Removing client on %d\n", fd);
					}
					else{
						read(fd, &ch, sizeof(ch));
						sleep(2);
						printf("Serving client on %d\n", fd);
						write(fd, &ch, sizeof(ch));
					}
				}
		}
	}
}

int main(int argc, char const *argv[])
{
	createServeSocket();
	performServerTask();
	return 0;
}