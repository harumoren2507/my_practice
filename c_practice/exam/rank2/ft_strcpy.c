char *ft_strcpy(char *s1, char *s2)
{
  char *first_s1;

  first_s1 = s1;

  while (*s2 != '\0')
  {
    *s1 = *s2;
    s1++;
    s2++;
  }
  *s1 = '\0';
  return (first_s1);
}

/*
#include <stdio.h>
int main(void)
{
  char s1[100];
  char *s2 = "abcdefg";
  char *str = ft_strcpy(s1, s2);
  ft_strcpy(s1, s2);
  printf("%s\n", str);
  return (0);
}
*/
