#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>

#define IDSIZE   10
#define NAMESIZE 20
#define LINESIZE 512

typedef struct {
  char    last[NAMESIZE];
  char    first[NAMESIZE];
} name;

typedef struct {
  char id[IDSIZE];
  name name;
  int s;
} record;

int read_record(record *prec) {
  char line[LINESIZE];
  int s, i, k, g;
  int onlyFirstLetter = 0;
  char ID[LINESIZE];
  char tempF[LINESIZE];
  char tempL[LINESIZE];

  printf("%s\n", "enter some data");

    if (!fgets(line, LINESIZE, stdin)) {
      printf("%s\n", "read error");
        return 0;
    }

    if (sscanf(line, "%s %s %s %d", ID, tempF, tempL, &s) != 4) {
      printf("%s\n", "wrong entry");
      return 0;
    }

    for (i = 0; tempF[i] != '\0'; i++) {
      tempF[i] = tolower(tempF[i]);
    }
    for (k = 0; tempL[k] != '\0'; k++) {
      tempL[k] = tolower(tempL[k]);
    }

    for (g = 1; ID[g] != '\0'; g++) {
      if (!isdigit(ID[g])) {
        printf("%s\n", "bad id");
        return -1;
      }
      onlyFirstLetter = 1;
    }

    if ((ID[0] == 'a' && strlen(ID) == 9) && (onlyFirstLetter)) {
      printf("%s\n", "good id");
      strcpy(prec->id, ID);
    } else {
      printf("%s\n", "bad id");
      return -1;
    }

    if (s <= 100 && s >= 0) {
      printf("%s\n", "good grade");
      prec->s = s;
    } else {
      printf("%s\n", "bad grade");
      return -1;
    }

    if ((strlen(tempF)) < 20 && (strlen(tempL)) < 20) {
      printf("%s\n", "good name lengths");
      strcpy(prec->name.first, tempF);
      strcpy(prec->name.last, tempL);
      return 1;
    }

    printf("%s\n", "bad");
    return -1;
}
void print_record(const record *prec) {
  printf("%s : %s : %s : %d\n", prec->id, prec->name.last, prec->name.first, prec->s);
}

int main(void) {
  record rec;
  int ret;
  ret = read_record(&rec);
  if (ret == 1) {
    print_record(&rec);
  }
}
