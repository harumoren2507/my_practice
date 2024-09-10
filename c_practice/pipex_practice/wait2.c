#include <stdlib.h>
#include <sys/wait.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
  pid_t pid;
  pid = fork();
  if (pid == -1)
  {
    perror("fork");
    exit(EXIT_FAILURE);
  }
  else if (pid == 0)
  {
    printf("I am the child process\n");
    sleep(2);
    exit(EXIT_SUCCESS);
  }
  else 
  {
    printf("I am the parent process\n");
    //waitに」NULLを入れる理由って何？
    wait(NULL);
    printf("child process terminated after a 2s delay\n");
  }
  return (EXIT_SUCCESS);
}
