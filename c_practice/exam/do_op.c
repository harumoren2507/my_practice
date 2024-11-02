#include <unistd.h>

int ft_atoi(char *str)
{
  int result;
  int sign;

  result = 0;
  sign = 1;

  if (*str == '+' || *str == '-')
  {
    if (*str == '-')
      sign *= -1;
    str++;
  }
  while (*str >= '0' && *str <= '9')
  {
    result = result * 10 + (*str - 48);
    str++;
  }
  return (sign * result);
}


void  ft_putnbr(int nb)
{
  if (nb == -2147483648)
  {
    write(1, "-2", 2);
    nb = 147483648;
  }
  if (nb < 0)
  {
    write(1, "-", 1);
    nb *= -1;
  }
  if (nb >= 10)
  {
    ft_putnbr(nb / 10);
    ft_putnbr(nb % 10);
  }
  if (nb < 10)
  {
    nb += 48;
    write(1, &nb, 1);
  }
}


int main(int  argc, char *argv[])
{
  int result;
  int left;
  int right;

  result = 0;
  left = 0;
  right = 0;

  if (argc == 4)
  {
    left = ft_atoi(argv[1]);
    right = ft_atoi(argv[3]);
    if (argv[2][0] == '*')
      result = left * right;
    else if (argv[2][0] == '/' && argv[3][0] != '0')
        result = left / right;
    else if (argv[2][0] == '+')
        result = left + right;
    else if (argv[2][0] == '-')
        result = left - right;
    ft_putnbr(result);
  }
  write(1, "\n", 1);
  return 0;
}


/*
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  char *str = "2147483647";
  int i = ft_atoi(str);
  printf("%d\n", i);
  return (0);
}*/
