#include <stdio.h>
#include <string.h>

void my_func(char *argv)
{
  char buffer[100];
  strncpy(buffer, argv, sizeof(buffer) - 1);
  printf(buffer);
  printf("\n");
}

int main(int argc, char *argv[])
{
  my_func(argv[1]);
  return (0);

}
