#include <stdio.h>
#include "./def.h"
#define MAX 1000

int main(void) {
  int b = 10 ;
  printf("%d", MAX + doit(b));
  return 0;
}

int doit(int b) {
  return MAX + b;
}
