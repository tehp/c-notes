#include <stdio.h>
#include <ctype.h>
#define LINESIZE 1024

int getInput() {
  char zero[10] = {0};
  char input[LINESIZE];
  char stdID[20];

  printf("Please enter a command:");
  printf("\n");
  fgets(input, sizeof(input), stdin);
  sscanf(input, "%s", stdID);

  /* check if input is 0 */
  if (strcmp(input,zero)) {
    printf("see 0");
  } else {
    printf("not see 0");
  }

  return 1;
}

int main(int argc, char **argv) {

  FILE *file = NULL;
  FILE *fp;

      if ((fopen(argv[1],"w"))!=NULL) {
        /** Opens and clears the file if it exists */
        printf("%s", argv[1]);
        printf(" exists!\n");
        fclose(file);
      } else {
        printf("the file you entered doesn't exist\n");
        /* Creates the file if it did not exist before */
        fp = fopen(argv[1],"a");
      }
      getInput();
}
