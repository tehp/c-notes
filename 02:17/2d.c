void reverse_cop (char dest[], const char src[]) {
  size_t i, j;
  for (i=strlen(src), j=0; i>0; i--, j++) {
    dest[j] = src[i-1];
  }
  dest[j] = '\0';
}
