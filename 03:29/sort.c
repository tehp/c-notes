#include <stdlib.h>
#include <string.h>
#include "types.h"

int cmp_by_id(const void *p, const void *q) {
  const Grade *pp = p;
  const Grade *qq = q;
  return strcmp(pp->id, qq->id);
}

void sort_by_id(Grade *a, size_t n) {
  qsort(a, n, sizeof(a[0]), cmp_by_id);
}

void sort(Grade *a, size_t n) {

}
