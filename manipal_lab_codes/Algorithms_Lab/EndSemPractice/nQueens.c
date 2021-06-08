#include <stdio.h>
#include <stdlib.h>

#define MAX 100
typedef enum {NO, YES} BOOL; 
int n;

void printBoard (int board[MAX][MAX]) {
	int i, j;
	for (i = 0; i < n; ++i) {
		for (j = 0; j < n; ++j) {
			printf("%c ", (board[i][j]) ? 'Q': '-');
		}
		printf("\n");
	}
	printf("\n");
}

BOOL issafeBoard(int b[][MAX], int row, int col){
	int i,j;
	for(int i=0; i<col; i++){
		if(b[row][i]){
			return NO;
		}
	}
	for(i=row, j = col; j>=0 && i>=0; i--, j--){
		if(b[i][j]){
			return NO;
		}
	}
	for(i=row, j = col; j>=0 && i<n; i++, j--){
		if(b[i][j]){
			return NO;
		}
	}
	return YES;
}

BOOL placeQueens(int b[][MAX], int col){
	if(col == n){
		return YES;
	}
	for(int i=0; i<n; i++){
		if(issafeBoard(b, i, col)){
			b[i][col] = 1;
			if (placeQueens(b, col+1)){
				return YES;
			}
			b[i][col] = 0;
		}
	}
	return NO;
}

int main (int argc, const char * argv []) {

	// printf("Enter the size of the board: ");
	scanf("%d", &n);
	int b[MAX][MAX];
	int i, j;
	for (i = 0; i < n; ++i) {
		for (j = 0; j < n; ++j) {
			b[i][j] = 0;
		}
	}

	if (placeQueens(b, 0)) {
		printf("Solution exists:\n");
		printBoard(b);
	} else {
		printf("No soluton exists.\n");
	}

}