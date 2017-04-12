#include <stdio.h>
#include "types.h"

int read_grade(Grade *p) {
  return scanf("%9s %d", p->id, &p->grade) == 2;
}

void print_grade(const Grade *p) {
  printf("%s %d\n", p->id, p->grade);
}
