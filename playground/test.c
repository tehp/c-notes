#include <stdio.h>
#include <ctype.h>

void squeeze_spaces(void);
void format_words(void);

int main(void)
{
  squeeze_spaces();
  format_words();
  return 0;
}


void squeeze_spaces(void) {
int character;
int space = 0;
while ((character = getchar()) != EOF) {
	if(!isspace(character)) {
		putchar(character);
		space = 0;
	} else if (isspace(character) && space == 0) {
		putchar(character);
		space = 1;
	  }
  }
}


void format_words(void)
{
    int character;
    int space = 0;
    while ((character = getchar()) != EOF)
    {
        if(isspace(character))
        {
            putchar(character);
            space = 1;
        }
        else if(space == 1)
        {
            putchar(toupper(character));
            space = 0;
        }
        else
        {
            putchar(tolower(character));
        }
    }
}
