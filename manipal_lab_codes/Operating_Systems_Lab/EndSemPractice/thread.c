#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/types.h>

int a[10], size;

void *sum(void *param){
	int step = (int)param;
	int x = 0;
	for(int i=step; i<size-1; i++){
		x += a[i];
		printf("%d\n", x);
		sleep(2);
		a[i] = (a[i] + 2)%a[i+1];
	}
	printf("Sum is %d\n", x);
}

int main(int argc, char const *argv[])
{
	int step1, step2;
	scanf("%d", &size);
	for(int i=0; i<size; i++){
		scanf("%d", &a[i]);
	}
	scanf("%d %d", &step1, &step2);
	pthread_t t1, t2;
	pthread_attr_t attr;
	pthread_attr_init(&attr);
	pthread_create(&t1, &attr, sum, (void*)step1);
	pthread_create(&t2, &attr, sum, (void*)step2);
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	return 0;
}