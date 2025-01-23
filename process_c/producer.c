#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>
#include<unistd.h>

#define buff_s 10
#define total_items 30
#define pros 3
#define cons 3

int buff[buff_s];
int in=0;
int out=0;
int count=0;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

sem_t full, empty;

void* produce(void* arg){
	int item;
	int id = *(int*)arg;

	for(int i=0;i<total_items/pros;i++){
		item= rand()%100;

		sem_wait(&empty);
		pthread_mutex_lock(&mutex);

		item=buff[in];
		in=(in+1)% buff_s;
		count++;

		printf("producer %d produced_item %d (count %d)\n",id,item,count);

		pthread_mutex_unlock(&mutex);
		sem_post(&full);

		sleep(1);
	}
	return NULL;
}

void* consume(void* arg){
        int item;
        int id = *(int*)arg;

        for(int i=0;i<total_items/cons;i++){
               

                sem_wait(&full);
                pthread_mutex_lock(&mutex);

                buff[out]=item;
                out=(out+1)% buff_s;
                count--;

                printf("consumer %d consumed_item %d (count %d)\n",id,item,count);

                pthread_mutex_unlock(&mutex);
                sem_post(&empty);

                sleep(2);
        }
        return NULL;
}

int main(){
	pthread_t pro[pros];
	pthread_t con[cons];
	
	int p[pros]={1,2,3};
	int c[cons]={1,2,3};

	sem_init(&empty,0,buff_s);
	sem_init(&full,0,0);

	for(int i=0;i<pros;i++){
		pthread_create(&pro[i],NULL,produce,&p[i]);
	}
	for(int i=0;i<cons;i++){
                pthread_create(&con[i],NULL,consume,&c[i]);
        }
	
	for(int i=0;i<pros;i++){
                pthread_join(pro[i],NULL);
        }

	 for(int i=0;i<cons;i++){
                pthread_join(con[i],NULL);
        }
	sem_destroy(&empty);
	sem_destroy(&full);
	
	return 0;
}

