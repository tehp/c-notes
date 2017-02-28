#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>

#define LINESIZE 512

/*
Mackenzie Craig
Set 2C - A00991048
COMP2510 - Assignment 1
*/

int checkBlank(char array[]);
int contains(char text[], FILE *fp);
int validate(char array[]);
int takeNameFirstLast(char *name);
int takeID(char *id, FILE *fp);
int takeGrade(int *grade);
void addRecord(FILE *fp);
void displayRecords(FILE *file);
void displayJustN(int num, FILE *file);
void displayAfterN(int num, FILE *file);
void optionSelect(FILE *file);
void printMenuString(void);
void nameToLower(char name[]);

int validate(char array[]) {

    int i;

    if(array[strlen(array) - 1] == '-' || array[0] == '-') {
        return 0;
    }

    for(i = 0; array[i] != '\0';i++) {

        if(!isalpha(array[i])) {

            if(array[i] == '-') {
                return 1;
            } else {
                return 0;
            }

        }

    }

    return 1;

}

int checkBlank(char array[]) {

    int i;

    for(i = 0; array[i] != '\0';i++) {
        if(!isspace(array[i])) {
            return 0;
        }
    }

    return 1;

}

int contains(char text[], FILE *fp) {

    char holder[LINESIZE];
    rewind(fp);

    while(fgets(holder, sizeof(holder),fp) != NULL) {

        if (strstr(holder, text) != NULL) {
            return 1;
        }

    }

    return 0;

}

void printMenuString(void) {

    fprintf(stderr, "%s\n", "Your choices: 0: Append new record, -n: Print all records after and including n, +n: Print record #n.");

}

void displayJustN(int num, FILE *file) {

    char s1[LINESIZE];
    char s2[LINESIZE];
    char s3[LINESIZE];
    char s4[LINESIZE];

    int numForRecord = 0;

    rewind(file);

    while(fscanf(file, "%s %s %s %s", s1, s2, s3, s4) != EOF) {

        numForRecord++;

        if(numForRecord == num) {
            printf("%s : %s %s : %s\n", s1, s2, s3, s4);
        }

    }

    printf("%d\n", 1);

}

void displayAfterN(int num, FILE *file) {

    char s1[LINESIZE];
    char s2[LINESIZE];
    char s3[LINESIZE];
    char s4[LINESIZE];

    int n = 0;
    int i = 0;

    rewind(file);

    while(fscanf(file, "%s %s %s %s", s1, s2, s3, s4) != EOF) {

        n++;

        if (n >= abs(num)) {

            i++;
            printf("%s : %s %s : %s\n", s1, s2, s3, s4);

        }

    }

    printf("%d\n", i);

}

int takeNameFirstLast(char *name) {

    char input[LINESIZE];
    char first[LINESIZE];
    char last[LINESIZE];

    while (1) {
        fprintf(stderr, "\n%s", "Enter first name, space, lastname:\n");

        if(checkBlank(input) == 1) {
            break;
        }

        if (!fgets(input, LINESIZE, stdin)) {
            clearerr(stdin);
            return 1;
        }

        if (sscanf(input, "%s %s", first, last) == 2) {

            if((strlen(first) > 1) && (strlen(first) < 20) && (strlen(last) > 1) && (strlen(last) < 20)) {

                if((validate(first) == 1) && (validate(last) == 1)) {

                    nameToLower(last);
                    nameToLower(first);

                    strcpy(name, last);

                    strcat(name, ", ");
                    strcat(name, first);

                    return 0;

                }
            }
        }
    }

    return 1;

}

int takeID(char *id, FILE *fp) {

    char input[LINESIZE];
    char holder[LINESIZE];

    while (1) {
        fprintf(stderr, "Enter ID:\n");

        if(checkBlank(input) == 1) {
            break;
        }

        if (!fgets(input, LINESIZE, stdin)) {
            clearerr(stdin);
            return 1;
        }

        if (sscanf(input, "%s", holder) == 1) {

            if (strlen(holder) == 9 && (int)holder[0] == 'a') {
                int i;

                for (i = 1; i < 9; i++) {

                    if (holder[i] < '0' || holder[i] > '9') {
                        break;
                    }

                }

                if (i == 9) {

                    if(contains(holder, fp) == 0) {
                        sscanf(holder, "%s ", id);
                        return 0;
                    }

                }
            }
        }
    }

    return 1;

}

int takeGrade(int *grade) {

    char input[LINESIZE];

    while (1) {
        fprintf(stderr, "Enter grade:\n");

        if(checkBlank(input) == 1) {
            break;
        }

        if (!fgets(input, LINESIZE, stdin)) {
            clearerr(stdin);
            return 1;
        }

        if (sscanf(input, "%d", grade) == 1) {
            if (isspace(input[0])) {
                return -1;
            }

            if (*grade >= 0 && *grade <= 100) {
                return 0;
            }

        }
    }

    return 1;

}

void nameToLower(char name[]) {

    int n;

    for (n=0; name[n]!='\0'; n++) {
        name[n] = tolower(name[n]);
    }

}

void addRecord(FILE *fp) {

    char name[LINESIZE];
    char stdID[LINESIZE];

    int grade;

    if (fseek(fp, 0, SEEK_END) != 0) {
        perror("Error during fseek in file.");
    }

    if (takeID(stdID, fp) == 0 && takeNameFirstLast(name) == 0 && takeGrade(&grade) == 0) {
        fprintf(fp, "%-10s%-40s%-3d\n", stdID, name, grade);
    }

}

void displayRecords(FILE *file) {

    char s1[LINESIZE];
    char s2[LINESIZE];
    char s3[LINESIZE];
    char s4[LINESIZE];

    int numForRecord = 0;

    rewind(file);

    while (fscanf(file, "%s %s %s %s", s1, s2, s3, s4) != EOF) {
        numForRecord++;
        printf("%s : %s %s : %s\n", s1, s2, s3, s4);
    }

    printf("%d\n", numForRecord);

}



void optionSelect(FILE *file) {

    char choice[LINESIZE];

    int check[LINESIZE];

    printMenuString();

    fprintf(stderr, "Enter one of the 3 choices: \n");

    while(fgets(choice, LINESIZE, stdin) != NULL) {

        if(sscanf(choice, "%d", check) == 1) {

            if(check[0] > 0) {
                displayJustN(check[0], file);
            } else if (check[0] == 0) {
                addRecord(file);
            } else if (check[0] == -1){
                displayRecords(file);
            } else if (check[0] <= -2) {
                displayAfterN(check[0], file);
            }

        }

        printMenuString();

        fprintf(stderr, "Enter one of the 3 choices: \n");

    }

    fprintf(stderr, "Closing\n");

}

int main (int argc, char *argv[]) {

    FILE * fp;
    fp = fopen(argv[1], "wb+");

    if (fp == NULL || argc > 2){

        printf("Please pass exactly 1 argument to this file in the form of <name>.txt");
        exit(0);

    }

    optionSelect(fp);
    fclose(fp);

    return 0;

}
