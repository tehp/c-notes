#include <stdio.h>
#include <ctype.h>

void squeeze_spaces(void);
void format_words(void);

int main(void)
{
  format_words();
  return 0;
}


void squeeze_spaces(void) {
int c = 0;
int sp = 0;
while ((c = getchar()) != EOF) {
  if(c != ' ') {
    sp = 0;
    putchar(c);
  } else if (c == ' ' && sp == 0) {
    sp = 1;
    putchar(c);
  }
}
}


void format_words(void) {
int c;
int sp = 1;
while ((c = getchar()) != EOF) {
    if(c == ' ' || c == '"' || c == '\t')
    {
        putchar(c);
        sp = 1;
    } else if (sp == 1) {
        putchar(toupper(c));
        sp = 0;
    } else {
          putchar(tolower(c));
    }
  }
}
