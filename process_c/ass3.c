#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int main(){
		
	int fd[2];
	pid_t pid;

	if ( pipe(fd) < 0){
		printf("error in creating pipe");
		exit(1);
	}
	
	pid = fork();

	if( pid == 0){
		close(fd[1]);
		int x;

		read(fd[0], &x ,sizeof(int));

		if ( x%2 ==0){
			printf("\nrecieved %d is even\n ", x);
		}else{
			printf("\nrecieved %d is odd\n " ,x);
		}
		close(fd[0]);
	}else{
		close(fd[0]);
		int n=33;
		write(fd[1], &n, sizeof(int));
		printf("\n %d sent to child process\n",n);
		close(fd[1]);
		wait(NULL);
	}




	return 0;
}
