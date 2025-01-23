#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include<semaphore.h>

#define reader 2
#define writer 10

sem_t wrt;

pthread_mutex_t mutex;

int num_read=0;
int count=1;

void* write_func(void *arg){
	int id= *(int*)arg;

	sem_wait(&wrt);
	//write
	count=count*2;
	printf("Writer %d  updated the count %d\n",id,count);

	sem_post(&wrt);

	
}

void* read_func(void *arg){

	int id= *(int*)arg;
	pthread_mutex_lock(&mutex);
	//inc
	num_read++;
	if(num_read==1){
		sem_wait(&wrt);
	}
	pthread_mutex_unlock(&mutex);

	printf("Reader %d read the count %d\n",id,count);

	pthread_mutex_lock(&mutex);
	//dec
	num_read--;
	if(num_read ==0){
		sem_post(&wrt);
	}
	pthread_mutex_unlock(&mutex);

	

}

int main(){
	pthread_t r[reader],w[writer];
	int re[reader]={1,2};
	int we[writer]={1,2,3,4,5};
	sem_init(&wrt,0,1);


	for(int i=0;i<writer;i++){
                pthread_create(&w[i], NULL,write_func, &we[i]);
        }

	for(int i=0;i<reader;i++){
		pthread_create(&r[i],NULL,read_func,&re[i]);
	
	}
	
	for(int i=0;i<writer;i++){
		pthread_join(w[i],NULL);
	}
	for(int i=0;i<reader;i++){
		pthread_join(r[i],NULL);
	}

	sem_destroy(&wrt);
	return 0;
}


