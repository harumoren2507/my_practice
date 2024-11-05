#include <unistd.h>

void  alpha_mirror(char *str)
{
  int i;

  i = 0;
  while (*str)
  {
    if (*str >= 'a' && *str <= 'm')
    {
      i = *str - 97;
      i = 25 - (i * 2);
      *str = *str + i;
      write (1, str, 1);
    }
    else if (*str >= 'A' && *str <= 'M')
    {
      i = *str - 65;
      i = 25 - (i * 2);
      *str = *str + i;
      write(1, str, 1);
    }
    else if (*str >= 'm' && *str <= 'z')
    {
      i = 122 - *str;
      i = 25 - (i * 2);
      *str = *str - i;
      write(1, str, 1);
    }
    else if (*str >= 'M' && *str <= 'Z')
    {
      i = 90 - *str;
      i = 25 - (i * 2);
      *str = *str - i;
      write(1, str, 1);
    }
    else
      write(1, str, 1);
    str++;
  }
}


int main(int argc, char *argv[])
{
  if (argc == 2)
  {
    alpha_mirror(argv[1]);
  }
  write(1, "\n", 1);
}
