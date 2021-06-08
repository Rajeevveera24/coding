#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <netinet/in.h>
#include <unistd.h>

void createServerSocket(int *server_sockfd, int server_len, struct sockaddr_in server_address) {
	*server_sockfd = socket(AF_INET,SOCK_STREAM,0);
	server_address.sin_family = AF_INET;
	server_address.sin_addr.s_addr = inet_addr("127.0.0.1");
	server_address.sin_port = htons(10200);
	server_len = sizeof(server_address);
	bind(*server_sockfd, (struct sockaddr *)&server_address, server_len);
	listen(*server_sockfd,5);
}

void performServerTask(int server_sockfd, int client_sockfd, int client_len, struct sockaddr_in client_address) {
	int result;
	fd_set readfds, testfds;
	FD_ZERO(&readfds);
	FD_SET(server_sockfd, &readfds);
	while(1) {
		char ch;
		int fd, nread;
		testfds = readfds;
		printf("Server Waiting!\n");
		result = select(FD_SETSIZE, &testfds, (fd_set *)0,(fd_set *)0,(struct timeval *)0);
		if(result < 1) {
			printf("Server Error!\n");
			exit(1);
		}
		for(fd = 0; fd < FD_SETSIZE ; fd++) {
			if(FD_ISSET(fd,&testfds)) {
				if(fd == server_sockfd) {
					client_len = sizeof(client_address);
					client_sockfd = accept(server_sockfd, (struct sockaddr *)&client_address,&client_len);
					FD_SET(client_sockfd, &readfds);
					printf("Adding Client of fd %d\n",client_sockfd);
				}
				else {
					ioctl(fd,FIONREAD,&nread);
					if(nread == 0) {
						close(fd);
						FD_CLR(fd,&readfds);
						printf("Removing Client on fd %d\n",fd);
					}
					else {
						read(fd,&ch,1);
						sleep(2);
						printf("Serving Client on fd %d\n",fd);
						if(ch == 'y') {
							char datetime[256];
							time_t current_time;
							struct tm *local_time;
							current_time = time(NULL);
							local_time = localtime(&current_time);
							strcpy(datetime, asctime(local_time));
							write(fd,&datetime,strlen(datetime));
						}
					}
				}
			}
		}
	}
}

int main() {
	int server_sockfd, client_sockfd, server_len, client_len;
	struct sockaddr_in server_address, client_address;
	createServerSocket(&server_sockfd,server_len,server_address);
	performServerTask(server_sockfd, client_sockfd, client_len, client_address);
}