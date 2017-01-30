#include <stdio.h>

#include <string.h>
#include <ctype.h>


#define CHECK(PRED) printf("%s...%s\n", (PRED) ? "  TEST PASSED" : "X TEST FAILED", #PRED);

size_t str_replace_all(char s[], int oldc, int newc);
size_t str_replace_last(char s[], int oldc, int newc);
size_t str_all_digits(const char s[]);
int str_equal(const char s[], const char t[]);

int main(void) {
  const char same1[] = "Hi";
  const char same2[] = "H";

  char s[] = "hello world";
  char x[] = "xxxxxxx";
  char y[] = "xxxxxxx";
  char z[] = "0123456789";
  char q[] = "hello123world";
  char j[] = "123hello123";


  printf("\n%s\n", "  Replace all test case");
  CHECK(str_replace_all(s, 'h', 'j') == 1);
  CHECK(strcmp(s, "jello world") == 0);
  CHECK(str_replace_all(s, 'j', 'i') == 1);

  printf("\n%s\n", "  Replace last test case");
  CHECK(str_replace_last(s, 'd', 'l') == 1);
  CHECK(strcmp(s, "iello worll") == 0);
  CHECK(str_replace_last(s, 'V', 'o') == 0);

  printf("\n%s\n", "  All digits test case");
  CHECK(str_all_digits(z) == 1);
  CHECK(str_all_digits(s) == 0);
  CHECK(str_all_digits(j) == 0);

  printf("\n%s\n", "  Equal test case");
  CHECK(str_equal(s, j) == 0);
  CHECK(str_equal(q, y) == 0);
  CHECK(str_equal(x, y) == 1);

  printf("\n%s\n", "  Equal test case (q2)");
  CHECK(str_equal(same2, same1) == 0);
}

size_t str_replace_all(char s[], int oldc, int newc) {

  size_t num = 0;
  int i = 0;

  for (i = 0; s[i] != '\0'; i++){
		if (s[i] == oldc) {
      s[i] = newc;
      num++;
    }
	}

  return num;
}

size_t str_replace_last(char s[], int oldc, int newc) {

  int iOfLastChar = -1;
  int i = 0;

  for (i = 0; s[i] != '\0'; i++) {
		if (s[i] == oldc) {
      iOfLastChar = i;
    }
	}

  if (iOfLastChar > -1) {
    s[iOfLastChar] = newc;
    return (size_t) 1;
  } else {
    return (size_t) 0;
  }

}



size_t str_all_digits(const char s[]) {

  int i = 0;
  /* 1 yes, 0 no*/
  for (i = 0; s[i] != '\0'; i++) {
		if (s[i] < '0' || s[i] > '9') {
      return 0;
    }
  }
  return 1;
}


int str_equal(const char s[], const char t[]) {

  int tf = 0;
  int i = 0;

  for (i = 0; s[i] != '\0' || t[i] != '\0'; i++) {
		if (s[i] == t[i]) {
      tf = 1;
    } else {
      tf = 0;
      break;
    }
  }

  return tf;
  /*true or false*/
}
