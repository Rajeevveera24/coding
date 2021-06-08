#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>
#include <unistd.h>

int buf[10], r = -1, f = -1;

sem_t mutex, full, empty;

void *produce(void * param){
	int i=0;
	do{
		sem_wait(&empty);
		sem_wait(&mutex);
		printf("Produced item is %d\n", i+1);
		buf[(++r)%10] = i+1;
		i++;
		sem_post(&mutex);
		sem_post(&full);
		sleep(2);
	}while(1);
}

void *consume( void* param){
	int i;
	do{
		sem_wait(&full);
		sem_wait(&mutex);
		i = buf[(++f)%10];
		printf("Consumed item is %d\n", i);
		sem_post(&mutex);
		sem_post(&empty);
		sleep(3);
	}while(1);
}

int main(int argc, char const *argv[])
{
	pthread_t t1, t2;
	sem_init(&mutex, 0, 1);
	sem_init(&empty, 0, 10);
	sem_init(&full, 0, 0);
	pthread_create(&t1, 0, produce, 0);
	pthread_create(&t2, 0, consume, 0);
	pthread_join(t1, 0);
	pthread_join(t2, 0);
	return 0;
}