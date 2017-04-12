#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>

#define LINESIZE = 1024;

int *arr_first_min(const int *a, size_t n) {

    const int *check;
    const int *found = a;

    for (check = a; check != a + n; check++) {

		    if (*check < *found) {
          found = check;
        }
		 }
    return (int*) found;
}

int *arr_last_min(const int *a, size_t n) {
    const int *check;
    const int *found = a;

    for (check = a; check != a + n; check++) {
		  if (*check <= *found) {
	    	found = check;
		  }
    }
    return (int*) found;
}


size_t str_replace_all(char *s, int oldc, int newc) {

    char *check;
    size_t numFound = 0;

    for (check = s; *check != '\0'; check++) {
	      if (*check == oldc) {
	         numFound++;
	         *check = newc;
	      }
    }
    return numFound;
}

char *str_find_last(const char *s, int c) {

   const char *check;
   const char *last = 0;

   for (check = s; *check != '\0'; check++) {
      if (*check == c) {
        last = check;
      }
    }

   return (char*) last;
}

int main(void) {
  int test[] = {1, 3, 4, 2};
  int test2[] = {6, 3, 2, 2, 7};
  char asdf[] = "asdf";

  int testPtr = *arr_first_min(test2, 5);
  int testPtr2 = *arr_last_min(test2, 5);

  if (*arr_first_min(test, 4) == 1) {
    printf("%s\n", "good");
  }
  if (*arr_first_min(test2, 5) == 2) {
    printf("%s\n", "good");
  }

  printf("%s\n", "----");



  printf("%d\n", &testPtr);
  printf("%d\n", &testPtr2);


  if (*arr_last_min(test, 4) == 1) {
    printf("%s\n", "good");
  }
  if (*arr_last_min(test2, 5) == 2) {
    printf("%s\n", "good");
  }

  printf("%s\n", "----");

  if (str_replace_all(asdf, 'a', 'z') == 1) {
    printf("%s\n", "good replace");
  }

  printf("%s\n", "----");

  if (*str_find_last(asdf, 'd') != NULL) {
    printf("%s\n", "good");
  }
}
