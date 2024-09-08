#include <stdio.h>
#include <unistd.h>

int   main(void) {

  if (unlink("example.txt") == 0)
  {
    printf("file successfully deleted!");
  }
  else {
    printf("Error deleting file");
  }
  return (0);
}
