#include <stdio.h>
#include <string.h>
#include <ctype.h>


int main(void) {

  int a[] = {1, 2, 3};
  printf("%d %d %d %d \n", &a[0], &a[1], &a[2], &a[3]);
  printf("%p %p %p %p \n", &a[0], &a[1], &a[2], &a[3]);

  return 1;
}
