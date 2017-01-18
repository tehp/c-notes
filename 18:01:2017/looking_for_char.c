size_t str_find (const char s[], in x) {
  size_t i;
  for (i=0; s[i]!='\0'; i++) {
    if (s[i] == x) {
      return i;
    }
  }
  return -1;
}
