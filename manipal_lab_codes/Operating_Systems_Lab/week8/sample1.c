#include <stdio.h>
#include <pthread.h>
int counter = 0;
void *func(void *params){
	counter++;
}
int main(int argc, char const *argv[])
{
	pthread_t thread[10];
	for(int i=0; i<10;i++){
		pthread_create(&thread[i], 0, func, 0);
		printf("Counter: %d\n", counter);
	}
	for(int i=0; i<10;i++){
		pthread_join(thread[i], 0);
		//printf("Counter: %d\n", counter);
	}
	return 0;
}