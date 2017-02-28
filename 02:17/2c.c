void lowercase_copy (chardest[], const char src[]) {
  size_t i;
  for (i=0; src[i]!='\0'; i++) {
    dest[i] = tolower(src[i]);
  }
  dest[i] = '\0';
}
