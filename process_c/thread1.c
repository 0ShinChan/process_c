#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

int count=0;

void* incre(void* arg){
	for(int i=0;i<=10000000;i++){

		count++;
	}
	return NULL;
}

int main(){
	pthread_t t1,t2;
	pthread_create(&t1,NULL,incre,NULL);
	pthread_create(&t2,NULL,incre,NULL);

	pthread_join(t1,NULL);
	pthread_join(t2,NULL);
	
	printf("count : %d",count);
	return 0;
}
