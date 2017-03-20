#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define LINESIZE 512

int truncate(char *s1, char *s2);
int range(char *s);
void drop(char s1[], int place);
void escapeSeq(char s1[]);
void trans (char s1[], char s2[]);
void extend (char *news1, char *s2);
void extend_checker (char s1[], char s2[]);
void prepare (char s1[], char s2[], char s3[]);
int main (int argc, char *argv[]);


/*
Mackenzie Craig
s 2C - A00991048
COMP2510 - Assignment 2
*/

/* Truncate the longer string */
int truncate(char *s1, char *s2) {

    int a, b;

    a = strlen(s1);
    b = strlen(s2);

    if (a > b) {
        s1[b] = '\0';
    }

    if (a < b) {
        s2[a] = '\0';
    }

    return 0;
}

/* Expand character ranges eg. a-d = abcd */
int range(char *s) {

    int i;
    int j;
    int k;

    int length = strlen(s);

    char b;
    char a;
    char temp[LINESIZE];
    char printIfErr[] = "entered range is not valid";

    for (i = 0; i < length; i++) {

        if (s[i] == '-' && (i != 0 && i != length - 1)) {

            b = s[i - 1];
            a = s[i + 1];

            if (b > a) {
              fprintf(stderr, "%s\n", printIfErr);
            }

            if (b == a) {
                strcpy(&s[i - 1], &s[i + 1]);
            } else {
                for (j = 0; b < a; b++, j++) {
                    temp[j] = b + 1;
                }
                temp[j] = '\0';
                /*Shifts the s array to the right to accomodate the expanded characters*/
                strcpy(&s[i + strlen(temp) - 1], &s[i + 1]);
                /*Copies the expanded array into the right positions*/
                for (j = i, k = 0; temp[k] != '\0'; k++, j++) {
                    s[j] = temp[k];
                }
            }
            length = strlen(s);
            i += strlen(temp);
        }
    }
    return 0;
}

/* Remove space. For use with escapeSeq() */
void drop(char s1[], int place) {

	int n;
	int length = 0;

  length = strlen(s1);

	for (n=place; n<length; n++) {
    /* move everything back 1 */
		s1[n] = s1[n+1];
	}
}

/* Remove slash, add escape in its place. Shift to compensate. */
void escapeSeq(char s1[]) {

	int i;
  int escapePlace;

	for (i=0; s1[i]!='\0'; i++) {

    /* check if slash */
		if (s1[i] == '\\') {
      escapePlace = i + 1;

      /* check what follows slash */
			if (s1[escapePlace] == 'a') {
				s1[i] = '\a';
				drop(s1, escapePlace);

			} else if (s1[escapePlace] == 'b') {
				s1[i] = '\b';
				drop(s1, i + 1);

			} else if (s1[escapePlace] == 'f') {
				s1[i] = '\f';
				drop(s1, escapePlace);

			} else if (s1[escapePlace] == 'n') {
				s1[i] = '\n';
				drop(s1, escapePlace);

			} else if (s1[escapePlace] == 'r') {
				s1[i] = '\r';
				drop(s1, escapePlace);

			} else if (s1[escapePlace] == 't') {
				s1[i] = '\t';
				drop(s1, escapePlace);

			} else if (s1[escapePlace] == 'v') {
				s1[i] = '\v';
				drop(s1, escapePlace);

      }	else if (s1[escapePlace] == '\\') {
      	s1[i] = '\\';
      	drop(s1, escapePlace);

			} else if (s1[escapePlace] == '\'') {
				s1[i] = '\'';
				drop(s1, escapePlace);

			} else if (s1[escapePlace] == '\"') {
				s1[i] = '\"';
				drop(s1, escapePlace);

      } else if (s1[escapePlace] == '\?') {
        s1[i] = '\?';
        drop(s1, escapePlace);
      }
		}
	}
}

/* Translate using two strings as patterns for conversion. */
void trans (char s1[], char s2[]) {

    int i;

    int n;
    int holder;

    char ascii[256];

    /* sup ascii array */
     for (n=0; n<256; n++) {
         ascii[n] = n;
     }

     /* trans */
     for (i=0; s1[i]!='\0'; i++) {
         if(s2[i]!=s1[i]) {
              ascii[(int)s1[i]] = s2[i];
         }
     }

     /* print back */
     while ((holder = getchar()) != EOF) {
         putchar(ascii[holder]);
     }
}

/* Extend a short string to match the length of a long string. */
void extend (char *news1, char *s2) {

    char final1;
    char final2;

    int s1Len;
    int s2Len;

    int i = 0;
    int j = 0;
    int k = 0;
    int m = 0;

    range(news1);
    range(s2);

    s1Len = strlen(news1);
    s2Len = strlen(s2);

    for (i = 0; news1[i] != '\0'; i++) {
      final1 = news1[i];
    }
    for (j = 0; s2[j] != '\0'; j++) {
      final2 = s2[j];
    }

    if (s1Len > s2Len) {
      for (k = s2Len; k < s1Len; k++) {
        s2[k] = final2;
        if (k == s1Len-1) {
          s2[k + 1] = '\0';
        }
      }
    } else if (s2Len > s1Len) {
      for (m = s1Len; m < s2Len; m++) {
        news1[m] = final1;
        if (m == s2Len-1) {
            news1[m + 1] = '\0';
        }
      }
   }
}

/* Check if extension is needed */
void extend_checker (char s1[], char s2[]) {

  char news1[LINESIZE];
  strcpy(news1, s1);

  escapeSeq(news1);
  escapeSeq(s2);
  range(news1);
  range(s2);

  if (strlen(news1) > strlen(s2)) {
    extend(news1, s2);
  } else if (strlen(s2) > strlen(news1)) {
    truncate(news1, s2);
  }

  trans(news1, s2);

}

/* Check params and prepare for translation */
void prepare (char s1[], char s2[], char s3[]) {

  char param[] = "-e";

  char news1[LINESIZE];
  strcpy(news1, s1);

  if (s3 == NULL) {

    escapeSeq(news1);
    escapeSeq(s2);
    range(news1);
    range(s2);
    truncate(news1, s2);
    trans(news1, s2);

  } else if ((strncmp(s1, param, LINESIZE)) == 0) {

    extend_checker(s2, s3);

  }
}

/*
Translates strings based on two params.
The first param is the characters that will be translated.
The second param is what the characters of the first param should be translated to.
Capable of expanding ranges of characters.
eg. a-d = abcd
Capable of converting manually typed escape sequences.
eg. '\' and 'n' = 'newline character'
*/
int main (int argc, char *argv[]) {

  if (argc < 3) {
    printf("wrong args");
    return 0;
  }

  prepare(argv[1], argv[2], argv[3]);

}
