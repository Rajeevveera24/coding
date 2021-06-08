#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>

sem_t mutex, wrt;
int data = 0, readCount = 0;

void *writer( void *param){
	int id = (int)param;
	do{
		sleep(1);
		sem_wait(&wrt);
		// sleep(1);
		printf("Writer %d changes %d to %d\n", id, data, (data+2)%7 );
		// sleep(1);
		data = (data+2)%7;
		sem_post(&wrt);
		sleep(2);
	}while(1);
}

void *reader(void *param){
	int id = (int)param;
	do{
		sleep(1);
		sem_wait(&mutex);
		readCount++;
		sleep(1);
		if(readCount == 1){
			sem_wait(&wrt);
		}
		sem_post(&mutex);
		// sleep(1);
		printf("Reader %d reads %d\n", id, data);
		sem_wait(&mutex);
		// sleep(3);
		readCount--;
		if(readCount == 0){
			sem_post(&wrt);
		}
		sem_post(&mutex);
		sleep(2);
	}while(1);
}

int main(){
	pthread_t r1, r2, r3, w1, w2;
	sem_init(&wrt, 1, 1);
	sem_init(&mutex, 1, 1);
	pthread_create(&w1, 0, writer, (void*)1);
	pthread_create(&r1, 0, reader, (void*)1);
	pthread_create(&r2, 0, reader, (void*)2);
	pthread_create(&w2, 0, writer, (void*)2);
	pthread_create(&r3, 0, reader, (void*)3);
	pthread_join(r2, 0);
	pthread_join(w2, 0);
	pthread_join(r3, 0);
	pthread_join(w1, 0);
	pthread_join(r1, 0);
	return 0;
}