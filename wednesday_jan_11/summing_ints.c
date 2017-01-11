int mian(void) {
  int a[] = {3, 2, 7, 6, 8};
  size_t i;
  int sum = 0;
  for (i = 0; i < 5; i++) {
    sum += a[i];
  }
  printf("%d\n",sum);
  return 0;
}
