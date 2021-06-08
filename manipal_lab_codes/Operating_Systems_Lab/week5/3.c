#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int num1, num2;

void isPrimePrint(int n){ 
    if (n <= 1){
    	return;
    } 
    if (n <= 3){
    	printf("%d\n", n);
    	return;
    } 
    if (n%2 == 0 || n%3 == 0){
    	return;
    } 
    for (int i=5; i*i<=n; i+=6) 
        if (n%i == 0 || n%(i+2) == 0){
           return;
        }
        printf("%d\n", n);
}

void * fun(void * arg){
	for(int i=num1; i<=num2; i++){
		isPrimePrint(i);
	}
}

int main(){

	printf("Enter the range: ");
	scanf("%d %d",&num1, &num2);

	pthread_t thread;
	pthread_attr_t attr;

	pthread_attr_init(&attr);

	pthread_create(&thread, &attr, fun, NULL);
	pthread_join(thread, NULL);
	return 0;
}