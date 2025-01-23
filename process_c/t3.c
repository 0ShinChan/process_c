#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>

sem_t sem_a,sem_b;
int a,b,c;
//first func
void* func_1(void* arg){
	printf("\nfor A: ");
	scanf("%d",&a);
	sem_post(&sem_a);
	return NULL;
}

void* func_2(void* arg){
	sem_wait(&sem_a);
	printf("\tfor B: ");
	scanf("%d",&b);
	sem_post(&sem_b);
	return NULL;
}

void* func_3(void* arg){
//	sem_wait(&sem_a);
	sem_wait(&sem_b);

	c=a+b;
	printf("\n result: %d",c);
	return NULL;
}

int main(){
	pthread_t t1,t2,t3;

	sem_init(&sem_a,0,0);
	sem_init(&sem_b,0,0);
//	sem_init(&sem_c,0,1);

	pthread_create(&t1,NULL,func_1,NULL);
        pthread_create(&t2,NULL,func_2,NULL);
        pthread_create(&t3,NULL,func_3,NULL);

	pthread_join(t1,NULL);
        pthread_join(t2,NULL);
        pthread_join(t3,NULL);
	
	
	sem_destroy(&sem_a);
        sem_destroy(&sem_b);
  //      sem_destroy(&sem_c);
	return 0;
}



	


