#include <assert.h>
int arr_max (count int a[], size_t n) {
  size_t i;
  int max;
  assert(n > 0);
  max = a(0);
  for (i=0, i<n; i++) {
    if (a[i] > max) {
      max = a[i];
    }
  }
  return max;
}
