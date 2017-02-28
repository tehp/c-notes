#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
  FILE *fp;
  int c;
  int n = 0;
  if ((argc = 2)) {
    fp = fopen(argv[1], "r");

    while(((c = getc(fp)) != EOF) && isalpha(getc(fp))) {
        n++;
    }
  }
  printf("%d\n", n);
}
