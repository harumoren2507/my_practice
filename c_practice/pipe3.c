#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

int main(void) {
  int fd[2];
  pid_t pid;
  char buffer[13];
  char write_message[] = "abcdefg";
  char read_message[100];

  if (pipe(fd) == -1)
  {
    perror("pipe");
    exit(EXIT_FAILURE);
  }

  pid = fork();
  if (pid == -1)
  {
    perror("fork");
    exit(EXIT_FAILURE);
  }
  if (pid == 0)
  {
    close(fd[0]);
    write(fd[1], write_message, strlen(write_message) + 1);
    close(fd[1]);
    wait(NULL);
  }
  else 
  {
    close(fd[1]);
    read(fd[0], read_message, sizeof(read_message));
    printf("%s\n", read_message);
    close(fd[0]);
  }
  return (0);
}
