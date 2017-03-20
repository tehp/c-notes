int *p, *tmp;
p = malloc(100*sizeof(int));
if (p == 0) {
  exit(1);
}

if (tmp == 0) {
  fprintf(stderr, "realloc failed\n");
} else {
  p = tmp;
  /* use p which now points to a block of new ints */
}
