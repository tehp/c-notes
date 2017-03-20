struct Grade c2510[120];
size_t i;
for (i=0; i<120; i++) {
  if (!read_grade(stdin, &a[i])) {
    break;
  }
}
