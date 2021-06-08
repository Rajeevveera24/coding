#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(){
	int cfd = socket(AF_INET, SOCK_DGRAM, 0);

	struct sockaddr_in caddr;

	caddr.sin_family = AF_INET;
	caddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	caddr.sin_port = htons(10200);

	int len = sizeof(caddr);
	printf("Enter number of rows and columns:\t");
	int m,n;

	scanf("%d %d", &m, &n);

	sendto(cfd, &m, sizeof(m), 0, (struct sockaddr*)&caddr, len);
	sendto(cfd, &n, sizeof(n), 0, (struct sockaddr*)&caddr, len);

	int row[n];

	for(int i=0; i<m; i++){
		printf("Enter elements for row %d : ", i+1);
		for(int j=0; j<n; j++)
			scanf("%d", &row[j]);
		sendto(cfd, row, sizeof(row), 0, (struct sockaddr*)&caddr, len);
	}
	
	printf("All rows sent to server\n");
	close(cfd);
	return 0;
}