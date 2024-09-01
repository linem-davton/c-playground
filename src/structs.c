#include <stdio.h>

int main(int argc, char *argv[]) {
  struct {
    int x;
    int y;
  } point;

  point.x = 10;
  point.y = 20;

  printf("point.x: %i\n", point.x);
  printf("point.y: %i\n", point.y);

  return 0;
}
