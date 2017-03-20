typedef struct Name {
  char first[24];
  char last[24];
} Name;

Name n; /* OK */
struct Name n2; /* also OK */

typedef struct { /* tag ommitted */
  char first[24];
  char last[24];
} Name;
Name n;
