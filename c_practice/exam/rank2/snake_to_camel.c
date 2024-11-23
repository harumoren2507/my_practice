#include <unistd.h>
#include <stdlib.h>

void  string_input(char *str)
{
  while (*str)
  {
    write(1, str, 1);
    str++;
  }
}

char*  snake_to_camel(char *str)
{
  int strnbr;
  int i;
  int j;
  int k;
  char *camel;

  strnbr = 0;
  i = 0;
  j = 0;
  k = 0;
  while (str[i])
  {
    if (str[i] != '_')
      strnbr++;
    i++;
  }
  camel = malloc(sizeof(char) * (strnbr + 1));
  if (camel == NULL)
  {
    free(camel);
    return NULL;
  }
  while (str[j])
  {
    if (str[j] == '_' && str[j + 1] != '\0')
    {
      if (str[j + 1] >= 'a' && str[j + 1] <= 'z')
        str[j + 1] -= 32;
    }
    if (str[j] != '_')
    {
      camel[k] = str[j];
      k++;
    }
    j++;
  }
  return (camel);
}


int main(int argc, char *argv[])
{
  char *str;
  if (argc == 2)
  {
    str = snake_to_camel(argv[1]);
    string_input(str);
    free(str);
  }
  write(1, "\n", 1);
}
