#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid;
    
    // Create a child process
    pid = fork();
    
    if (pid < 0) {
        // Fork failed
        perror("Fork failed");
        exit(1);
    }
    else if (pid == 0) {
        // Child process
        printf("Child process is running\n");
        printf("Child's PID: %d\n", getpid());
        printf("Child's parent PID: %d\n", getppid());
        
        // Child process exits immediately
        exit(0);
    }
    else {
        // Parent process
        printf("Parent process is running\n");
        printf("Parent's PID: %d\n", getpid());
        printf("Parent's child PID: %d\n", pid);
        
        // Parent sleeps for 30 seconds without waiting for child
        printf("\nChild process has terminated but parent hasn't waited.\n");
        printf("Child is now a zombie process.\n");
        printf("\nRun 'ps aux | grep defunct' in another terminal to see the zombie process.\n");
        printf("Or use 'ps -l' to see the process with status 'Z+'\n");
        
        sleep(30);  // Sleep to keep zombie process visible
        
        // Optional: Now wait for child to cleanup zombie
        printf("\nParent is now waiting for child...\n");
        wait(NULL);
        printf("Zombie process cleaned up\n");
    }
    
    return 0;
}
