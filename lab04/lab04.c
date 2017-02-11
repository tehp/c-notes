#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define LINESIZE 512


int get_word (const char prompt[], char word[], size_t max){

    char in[LINESIZE];
    char holder[LINESIZE];

    printf("%s ",prompt);

    while(fgets(in, LINESIZE, stdin) != NULL){
        if (sscanf (in, "%s", holder) == 1){
            if(strlen(holder) < max) {
                strcpy(word, holder);
                printf("%s", word);
                printf(" is the word you entered\n");
                return 1;
            }
            printf("not within bounds... try again: ");
        } else {
            /* nothing entered */
            printf("exiting\n\n");
            return 0;
        }
    }
    return 0;
}

int get_int(const char prompt[], int min, int max) {
    char in [LINESIZE];
    int integer;
    int loop = 1;

    printf("%s ", prompt);

    while(fgets(in, LINESIZE, stdin) != NULL || loop == 1){
        if (sscanf (in, "%d", &integer) == 1){
            if((integer >= min) && (integer <= max)){
                printf("%d", integer);
                printf(" is the int you entered.\n");
                loop = 0;
                return integer;
            }
            printf("not within bounds... try again: ");
        } else {
          return -1;
        }
    }
    return 0;
}

int main (){
      char word_p[] = "type a word";
      char num_p[] = "type an int";

      char word_1[5];

      get_word(word_p, word_1, 10);
      printf("\n");
      /* 1-10 */
      get_int(num_p, 1, 10);

      return 1;
}
