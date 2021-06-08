#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

int buf[5], f = -1,r = -1;
sem_t mutex, full, empty;
void *produce(void *param){
	int i = 0;
	do{
		sem_wait(&empty);
		sem_wait(&mutex);
		i = i % 5;
		printf("Produced item is %d\n", i+1);
		buf[(++r)%5] = i+1;
		i++;
		//sleep(1);
		sem_post(&mutex);
		sem_post(&full);
		//sleep(1);
		//printf("Full %u\n", full);
	}while(1);
}
void *consume(void *arg){
	int item;
	do{
		sem_wait(&full);
		//printf("Full %u\n", full);
		sem_wait(&mutex);
		item = buf[(++f)%5];
		printf("Consumed item is %d\n", item);
		//sleep(1);
		sem_post(&mutex);
		sem_post(&empty);
		//sleep(1);
	}while(1);
}
int main(int argc, char const *argv[])
{
	pthread_t thread1, thread2;
	sem_init(&mutex, 0, 1);
	sem_init(&full, 0, 0);
	sem_init(&empty, 0, 5);
	pthread_create(&thread1, NULL, produce, NULL);
	pthread_create(&thread2, NULL, consume, NULL);
	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);
	return 0;
}