#include <stdio.h>

int main(int argc, char * argv[]) {
  FILE *ifp, *ofp;

  if (argc != 3) {
    printf(stderr, "usage: %s [source] [destination]\n", argv[0]);
    return 1;
  }

  if ((ifp = fopen(argv[1], "rb")) == 0) {
    perror("fopen");
    return 2;
  }

  if ((ofp = fopen (argv[2], "wb")) == 0) {
    perror("fopen");
    return 3;
  }

  while ((c = fgetc(ifp)) != EOF) {
    fputc(c, ofp);
  }

  if (fclose(ifp) != 0) {
    perror("fclose");
    return 5;
  }

  return 0;
}
