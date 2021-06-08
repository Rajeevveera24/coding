#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

sem_t mutex, wrt;
int data = 0, readCount = 0;

void *writer(void *param){
	do{
		sleep(1);
		sem_wait(&wrt);
		data = (data + 2)%7;
		printf("Writer is writing %d\n", data);
		sem_post(&wrt);
	}while(1);
}
void *reader(void *arg){
	do{
		sleep(1);
		sem_wait(&mutex);
		readCount++;
		if(readCount == 1){
			sem_wait(&wrt);
		}
		sem_post(&mutex);
		printf("%d reader(s) are reading %d\n", readCount, data);
		sem_wait(&mutex);
		readCount--;
		if(readCount == 0){
			sem_post(&wrt);
		}
		sem_post(&mutex);
	}while(1);
}

int main(int argc, char const *argv[]){
	pthread_t thread1, thread2, thread3, thread4;
	sem_init(&mutex, 1, 1);
	sem_init(&wrt, 1, 1);
	pthread_create(&thread1, NULL, writer, NULL);
	pthread_create(&thread2, NULL, reader, NULL);
	pthread_create(&thread3, NULL, reader, NULL);
	pthread_create(&thread4, NULL, writer, NULL);
	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);
	pthread_join(thread4, NULL);
	pthread_join(thread3, NULL);
	return 0;
}