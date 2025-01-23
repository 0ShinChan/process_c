#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

void create_tree(int low, int max){
	if(low>=max) return;

	pid_t l_child,r_child;
	
	l_child=fork();

	if(l_child <0){
		printf("failed to create left child process");
		exit(1);
	}
	else if(l_child ==0){
		printf("process %d level %d parent %d",getpid(),low+1,getppid());
		create_tree(low+1,max);
		sleep(5);
		exit(0);
	}
	else{
		r_child=fork();
		if(r_child <0){
                printf("failed to create left child process");
                exit(1);
       		 }
       		 else if(r_child ==0){
                printf("process %d level %d parent %d",getpid(),low+1,getppid());
                create_tree(low+1,max);
                sleep(5);
                exit(0);
       		 }
		else{
			wait(NULL);
			wait(NULL);
		}
	}
}
	



int main(){
	printf("\ncreating process tree\n root process ID: %d\n",getpid());
	create_tree(0,3);
	printf("tree generation successfull!");

	return 0;
}
