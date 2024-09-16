#include <stdio.h>

#define STACK_SIZE 10

struct stack{
  int num;
  int data[STACK_SIZE];
};
typedef struct stack stack_t;



int stack_push(stack_t *stk, int push_data)
{
  if (stk->num >= STACK_SIZE)
    return (-1);
  stk->data[stk->num] = push_data;
  stk->num++;
  return (0);
}


int stack_pop(stack_t *stk, int *pop_data)
{
  if (stk->num < 1)
    return (-1);
  stk->num--;
  *pop_data = stk->data[stk->num];
  stk->data[stk->num + 1] = 0; 
  return (0);
}


void  stack_print(stack_t *stk)
{
  int i;
  i = 0;
  printf("stack :[");
  while (i < 10)
  {
    printf("%d", stk->data[i]);
    i++;
  }
  printf("]\n");
}



void  stack_init(stack_t *stk)
{
  stk->num = 0;
}


int main(void)
{
  stack_t stk ={0};
  int data;
  data = 0;

  stack_init(&stk);

  while (stack_push(&stk, data) == 0)
  {
    printf("(push %2d)", data);
    stack_print(&stk);
    data++;
  }
  while (stack_pop(&stk, &data) == 0)
  {
    printf("(pop %2d)", data);
    stack_print(&stk);
  }
  return (0);
}
