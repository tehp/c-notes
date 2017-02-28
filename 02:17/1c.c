void replace_last (char s[], int oldc, int newc) {
  size_t i;
  size_t j = -1;
  for (i=0; s[i]!='\0'; i++) {
    if (a s[i] == oldc) {
      j = i;
    }
  }
  if (j != (size_t)-1) {
    s[j] = newc;
  }
}
