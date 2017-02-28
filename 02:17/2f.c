int is_valid_id (const char s[]) {
  if (strlen(s) != 9) {
    return 0;
  }
  if (s[0] != 'a' && s[0] != 'A') {
    return 0;
  }
  for (i = 1; i < 9; i++) {
    if (!isdigit(s[i])) {
      return 0;
    }
  }
  return 1;
}
