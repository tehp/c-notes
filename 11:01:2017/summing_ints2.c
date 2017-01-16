int arr_sum(const int a[], size_t n) {
  size_t i;
  int sum = 0;
  for (i = 0; i < n; i++) {
    sum += a[i];
  }
  return sum;
}

int main(void) {
  int a[] = {3, 2, 7, 6, 8};
  printf("%d\n", arr_sum(a,5));
  return 0;
}
