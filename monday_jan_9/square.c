#include <stdio.h>

int square(int);

int main(void) {
  int n = 12;
  printf("%d\n", square(n));
  return 0;
}

int square(int x){
  return x * x;
}
