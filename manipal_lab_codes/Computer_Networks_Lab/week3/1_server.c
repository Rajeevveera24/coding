#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(){

	int sfd = socket(AF_INET, SOCK_DGRAM, 0);

	struct sockaddr_in s_addr, c_addr;
	s_addr.sin_family = AF_INET;
	s_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	s_addr.sin_port = htons(10200);

	bind(sfd, (struct sockaddr *)&s_addr, sizeof(s_addr));

	char buf[256];
	int c_len = sizeof(c_addr);
	int m,n;

	recvfrom(sfd, &m, sizeof(m), 0, (struct sockaddr *)&c_addr, &c_len);
	recvfrom(sfd, &n, sizeof(n), 0, (struct sockaddr *)&c_addr, &c_len);
	
	int mat[m][n],row[n];
	
	for(int i=0; i<m; i++){
		recvfrom(sfd, row, sizeof(row), 0, (struct sockaddr *)&c_addr, &c_len);
		for(int j=0; j<n; j++){
			mat[i][j] = row[j];
		}
	}

	printf("The matrix formed is :\n");

	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++)
			printf("%d ", mat[i][j]);
		printf("\n");
	}
	
	close(sfd);
	return 0;
}