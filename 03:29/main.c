#include <stdio.h>
#include "types.h"
#include "io.h"
#include "sort.h"

int main(void) {
  Grade a[100];
  Grade g;
  size_t i, j;

  for(i=0; i < 100; i++) {
    if (!read_grade(&g)) {
      break;

      
    }
    a[i] = g;
  }
}
