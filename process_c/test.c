#include <stdio.h>
 #include <unistd.h>
 int main() {
 int fd[2];
 pid_t pid;
 if (pipe(fd) == -1) {
 perror("Pipe failed");
 return 1;
 }
 pid = fork();
 if (pid < 0) {
 perror("Fork failed");
 return 1;
 }
 if (pid > 0) {  // Parent process
 close(fd[0]);  // Close reading end
 int num;
 printf("Parent: Enter a number: ");
 scanf("%d", &num);
 write(fd[1], &num, sizeof(num));
 close(fd[1]);  // Close writing end
 } else {  // Child process
 close(fd[1]);  // Close writing end
 int num;
 read(fd[0], &num, sizeof(num));
 close(fd[0]);  // Close reading end
 if (num % 2 == 0)
 printf("Child: %d is even.\n", num);
 else
 printf("Child: %d is odd.\n", num);
 }
 return 0;
 }
