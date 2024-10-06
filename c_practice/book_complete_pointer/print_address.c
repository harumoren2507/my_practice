#include <stdio.h>
#include <stdlib.h>

int global_variable;

static int  variable;


void  func1(void)
{
  int func1_variable;
  static int local_static_variable;

  printf("&func1_variable..%p\n", &func1_variable);
  printf("&local_static_variable..%p\n", &local_static_variable);
}

void  func2(void)
{
  int func2_variable;

  printf("&func2_variable..%p\n", &func2_variable);
}

int main(void)
{
  int *p;

  printf("func1..%p\n", (void*)func1);
  printf("func1(no_void)..%p\n", func1);

  printf("string literal..%p\n", "abc");
}
