#include <ctype.h>
int str_all_alpha(const char s[]) {
  size_t i;
  for (i=0; s[i]!='\0'; i++) {
    if (!isalpha(s[i])) {
      return 0;
    }
  }
  return 1;
}
