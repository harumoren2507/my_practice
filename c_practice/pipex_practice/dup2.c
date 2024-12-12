#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(void)
{
  int fd;
  fd = open("example.txt2", O_WRONLY | O_CREAT, 0644);
  close(STDIN_FILENO);
  dup2(fd, STDOUT_FILENO);
  close(fd);
  printf("This is printed in example.txt!\n");
  return (0);
}

