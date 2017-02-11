int arr_max(count int a[], size_t n) {
  size_t i;
  int max = a[0];
  for (i =0, i<n, i++) {
    if (a[i] > max) {
      max = a[i];
    }
  }
  return max;
}

int a[] = {3, 2, 7, 6, 8};
int max = arr_max(a, 5);
