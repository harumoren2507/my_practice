#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void rostring(char *str)
{
  char *str_tmp;
  str_tmp = NULL;
  char *first;
  first = NULL;
  int i;
  int first_str_size;

  i = 0;
  first_str_size = 0;
  while (str[i] == ' ' || str[i] == '\t')
    i++;
  while (str[i] != ' ' && str[i] != '\t')
  {
    i++;
    first_str_size++;
  }
  str_tmp = malloc(100 + 1);
  first = str_tmp;
  while (first_str_size != 0)
  {
    *str_tmp = str[i];
    printf("%d\n", *str_tmp);
    str_tmp++;
    i++;
    first_str_size--;
  }
  *str_tmp = '\0';
  printf("%s\n", first);
}

int main(int argc, char *argv[])
{

  if (argc == 2)
    rostring(argv[1]);
  return (0);
}

