#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int main(){
	pid_t pid;

	pid=fork();

	if(pid < 0){
		printf("Error while forking");
		exit(1);
	}
	if(pid == 0){
		printf("Child process is running\n");
		printf(" ID : %d\n parent ID : %d",getpid(),getppid());

		exit(0);
	}else {
		printf("\nparent process entered\nID: %d", getpid());
		
		printf("parent zombie process created");
		sleep(40);
	}

	return 0;
}

