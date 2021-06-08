

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int opcount = 0;

void shiftTable(char arr[], int table[], int m) {
	for(int i = 30 ; i < 123 ; i++)
		table[i] = m;
	for(int i = 0 ; i < m-1 ; i++)
		table[arr[i]] = (m - 1 - i);
}

int horsepool(char mstr[], char sstr[], int n, int m) {
	int table[130] = {0};
	shiftTable(sstr, table, m);
	int k = 0, i = m - 1;
	while(i <= n-1) {
		k = 0;
		while(opcount++ && k <= m-1 && sstr[m-1-k] == mstr[i-k])
			k++;
		if(k == m)
			return i-m+2;
		else
			i += table[mstr[i]];
	}
	return -1;
}

void main() {
	char mstr[40], sstr[20];
	printf("Enter Main String: ");
	gets(mstr);
	printf("Enter Sub String: ");
	gets(sstr);
	int pos = horsepool(mstr, sstr, strlen(mstr), strlen(sstr));
	if(pos == -1)
		printf("\nString not found!\n");
	else
		printf("\nString found at position: %d\n", pos);
	printf("\nopcount: %d\n", opcount);
}