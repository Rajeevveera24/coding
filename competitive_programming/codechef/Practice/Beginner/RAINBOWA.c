#include <stdio.h>
#include <stdlib.h>

// void print(int a[], int size){
// 	for(int i=0; i<size; i++){
// 		printf("%d ", a[i]);
// 	}
// 	printf("\n");
// }

int main(int argc, char const *argv[]){
	int t, n, a[100], cur, flag = 1, count[7] = {0,0,0,0,0,0,0};
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i=0; i<n; i++){
			scanf("%d", &a[i]);
			if(a[i] < 1 || a[i] > 7){
				flag = 0;
				break;
			}
			count[a[i] - 1]++;
		}
		for(int i=0; i<7; i++){
			if(count[i] == 0){
				flag = 0;
				break;
			}
		}
		if(flag == 0){
			printf("no\n");
			continue;
		}
		flag = cur = 1;
		for(int i=0; i<n/2; i++){
			// if(a[i] > 7 || a[i] <1){
			// 	flag = 0;
			// 	break;
			// }
			if(a[i] != a[n-i-1]){
				flag = 0;
				break;
			}
			if(a[i] < cur){
				flag = 0;
				break;
			}
			cur = a[i];
		}
		if(flag == 0){
			printf("no\n");
		}
		else{
			printf("yes\n");
		}
	}
	return 0;
}