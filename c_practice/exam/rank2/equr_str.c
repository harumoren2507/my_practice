#include <unistd.h>

int serach_last_str(char *str)
{
  int len;
  len = 0;

  while (*str)
  {
    str++;
    len++;
  }
  str--;
  while(*str)
  {
    if (*str != ' ' && *str != '\t')
      break ;
    len--;
    str--;
  }
  return (len);
}

void  equr_str(char *str)
{
  int i;
  int end;

  i = 0;
  end = serach_last_str(str);
  while (str[i] == ' ' || str[i] == '\t')
    i++;
  while (str[i] && i != end)
  {
    if (str[i] == ' ' || str[i] == '\t')
    {
      write(1, &str[i], 1);
      while (str[i] == ' ')
        i++;
    }
    else if (str[i] != ' ')
    {
      write(1, &str[i], 1);
      i++;
    }
  }
}

int main(int argc, char *argv[])
{
  if (argc == 2)
  {
    equr_str(argv[1]);
  }
  write(1, "\n", 1);
}
