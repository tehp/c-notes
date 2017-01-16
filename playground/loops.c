#include <stdio.h>
#include <string.h>

int main(void) {
  size_t i = 0;
  int a = 0;
  if (a == 0) {
    for (i = 0; i <= 600; i++) {
      char randomletter = 'A' + (random() % 26);
      if (randomletter == 'A') {
        a++;
      }
      printf("%c",randomletter);
    }
    printf("\n");
    printf("\n");
    printf(a);
  }
  return 0;
}
