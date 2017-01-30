FILE *fp;
if ((fp = fopen(filename, mode)) == NULL) {
  perror("fopen");
  /* Additional error handling */
}
