typedef struct    s_list
{
    struct s_list *next;
    void          *data;
}                 t_list;

int     ft_list_size(t_list *begin_list)
{
  t_list *current;

  current = begin_list;
  int list_size;

  list_size = 0;
  while (current)
  {
    list_size++;
    current = current->next;
  }
  return (list_size);
}

/*
#include <stdio.h>

int main(void)
{
  t_list *start = malloc(sizeof(t_list));
  t_list *second = malloc(sizeof(t_list));
  t_list *third = malloc(sizeof(t_list));


  start->next = second;
  second->next = third;
  third = NULL;

  int i;
  i = 0;
  i = ft_list_size(start);
  printf("%d\n", i);
  return (0);
}
*/
