int match(void) {
  int x = 1;
  printf("%d\n",x);
  int y = 2; /* error, not at the start of the block */
  if (x >0) {
    int z = 3; /* okay */
  }
  int z = 4; /* error, not at the start of the block */
}
