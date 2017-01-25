int arr_all_nonneg (const int a[], size_t n) {
  size_t i;
  for (i=0; i<n; i++) {
    if (a[i] < 0) {
      return 0;
    }
  }
  return 1;
}
