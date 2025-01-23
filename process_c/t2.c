#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>

int count=0;
sem_t mutex;

void* incre(void* arg){
	for(int i=0;i<1000000;i++){
		sem_wait(&mutex);
		count++;
		sem_post(&mutex);
	}
}

int main() {
	sem_init(&mutex,0,1);

	pthread_t t1,t2,t3;

	pthread_create(&t1,NULL, incre,NULL);
       	pthread_create(&t2,NULL, incre,NULL);
       	pthread_create(&t3,NULL, incre,NULL);

	 pthread_join(t1,NULL);
	 pthread_join(t2,NULL);
	 pthread_join(t3,NULL);
	
	   printf("\ncount: %d \n",count);

	    sem_destroy(&mutex);
	    return 0;
}
