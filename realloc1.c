#include <stdio.h>
#include <stdlib.h>

int main(void) {
  char *ptr;
  int i;

  i = 0;
  ptr = malloc(1);
  if (ptr == NULL)
    return (NULL);
  printf("address:%p size:1\n", ptr);

  while (i < 100)
  {
    i++;
    ptr = realloc(ptr, i);
    printf("address:%p size:%d\n", ptr, i);
  }
  free(ptr);
  return (0);
}

