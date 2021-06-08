#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

int *fibseq;
int i=0, n;

void * fibo(void * arg);

int main(){
	
	pthread_t thread; 
	pthread_attr_t attr;

	printf("Enter the value of n: ");
	scanf("%d", &n);

	fibseq = (int*)malloc(n * sizeof(int));

	pthread_attr_init(&attr);

	pthread_create(&thread, &attr, fibo, NULL);

	printf("The first %d fibonacci numbers are: ", &n);
	
	pthread_join(thread, NULL);

	for(int j=0; j<n; j++){
		printf("%d ", fibseq[j]);
	}
	printf("\n");

	return 0;
}

void * fibo(void * arg){
	while(i<n){
		if(i==0 || i==1){
			fibseq[i] = i;
		}
		else{
			fibseq[i] = fibseq[i-1] + fibseq[i-2];
		}
		i++;
	}
}