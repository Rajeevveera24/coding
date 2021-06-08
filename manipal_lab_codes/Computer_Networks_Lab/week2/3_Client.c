#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

void createClientSocket(int *len, int *result, int *sockfd, struct sockaddr_in address) {
	*sockfd = socket(AF_INET,SOCK_STREAM,0);
	address.sin_family = AF_INET;
	address.sin_addr.s_addr = inet_addr("127.0.0.1");
	address.sin_port = htons(10200);
	*len = sizeof(address);
	*result = connect(*sockfd, (struct sockaddr *)&address,*len);
}

void performClientTask(int sockfd) {
	int n = 1, pid = 0;
	int x;
	printf("\nEnter Length of Array: ");
	scanf("%d",&x);
	int arr[x];
	printf("\nEnter Array: ");
	for (int i = 0; i < x; ++i)
		scanf("%d",&arr[i]);
	write(sockfd,&x,sizeof(int));
	write(sockfd,&arr,x*sizeof(int));
	printf("\nSorted Array is: ");
	n = read(sockfd,&arr,x*sizeof(int));
	for (int i = 0; i < x; ++i)
		printf("%d ",arr[i]);
	n = read(sockfd,&pid,sizeof(int));
	printf("\nPID Value: %d\n",pid);
}

int main() {
	int len, result, sockfd;
	struct sockaddr_in address;
	createClientSocket(&len,&result,&sockfd,address);
	if(result == -1) {
		perror("\nClient Error.");
		exit(1);
	}
	performClientTask(sockfd);
}
