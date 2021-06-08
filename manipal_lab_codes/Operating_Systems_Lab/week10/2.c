#include <stdio.h>

#define NUM_PAGE 8
#define PAGE_SIZE 32

int main(int argc, char const *argv[]){
	int pgNum, offset, logicAddr;
	printf("Enter the logical address: ");
	scanf("%d", &logicAddr);

	pgNum = logicAddr/PAGE_SIZE + 1;
	offset = logicAddr%PAGE_SIZE;

	printf("The page number is %d and offset is %d\n", pgNum, offset);
	return 0;
}