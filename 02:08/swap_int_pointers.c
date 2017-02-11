void swap(int **p, int **q) {

  int m = 1, n = 2;
  int *a = &m, *b = &n;

  swap(&a, &b);

  int *tmp = p;
  p = q;
  q = tmp;
}
