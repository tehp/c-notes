int *p;
p = malloc(100* sizeof(int));
if (p == 0) {
  fprintf(stderr, "unable to allocate memory!\n");
  exit(0);
}

for (i = 0; i<100; i++) {
  p[i] = 3*i;
}
free(p);
