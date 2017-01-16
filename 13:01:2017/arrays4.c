size_t arr_find(const int a[], size_t n, int x) {
  size_t i;
  for (i=0; i<n; i++) {
    if (a[i] == x) {
      return i;
    }
  }
  return -1;
}
