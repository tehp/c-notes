void str_copy (char dest[], const char src[]) {
  size_t i;
  for (i=0; src[i]!='\0'; i++) {
    dest[i] = src[i];
  }
  dest[i] = '\0'; /* important to terminate dest with null char */
}
