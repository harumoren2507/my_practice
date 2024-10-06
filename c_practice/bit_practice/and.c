#include <stdio.h>

int main(void)
{
  printf("%08x\n", 0x01234567 & 0x000ff000);
  return (0);
}
