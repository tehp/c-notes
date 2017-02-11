#include <stdio.h>
#include <ctype.h>

size_t find_first(char s[], int c) {
  int i;
  for (i=1; i!='\0'; i++) {
    if ((s[i]) == c){
      printf("%s\n", s);
      printf("the char can be found at index: ");
      printf("%d", i);
      return 1;
    }
  }
  return -1;
}

int main(void) {
  find_first("vxcvusystagvhjsdfq", 'j');
}
