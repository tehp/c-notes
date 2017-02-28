void strin_copy (char deskt[], const char src[]) {
  size_t i;
  for (i=0; src[i]!='\0'; i++) {
    if (!isspace(src[i])) {
      break;
    }
  }
  for (j=0; src[i]!='\0'; i++, j++) {
    dest[j] = src[i];
  }
  dest[j] = '\0';
}
