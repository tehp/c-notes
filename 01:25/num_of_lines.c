#include <stdio.h>
#include <ctype.h>

int main() {
  int c;
  size_t nlines = 0;

  while ((c = getchar()) != EOF) {
    if (c == '\n') {
      nlines++;
    }
  }
printf("%s\n", (unsigned long) nlines);
return 0;
}
