#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/wait.h>

int main(){
	char str[100];
	char st[100];
	int fd[2];
	pid_t pid;
	if(pipe(fd) == -1){
			printf("failed to create a pipe");
			exit(1);
	}
	
	pid=fork();

	if(pid < 0){
		printf("fork failed");
		exit(1);
	}
	else{
		if(pid == 0){
			close(fd[1]);
			read(fd[0], st, sizeof(st));
			int len = strlen(st);
			for(int i=len -1;i>0;i--){
				printf("%c",st[i]);
			}

			close(fd[0]);

		}
		else{
			close(fd[0]);
			printf("\nEnter a sentence: ");
			fgets(str, sizeof(str), stdin);
		//	str[strcspn(str, "\n")]=0;
			write(fd[1], str,sizeof(str));
			close(fd[1]);

			wait(NULL);
		
		}

	}
				
    printf("\n");

    return 0;
}
