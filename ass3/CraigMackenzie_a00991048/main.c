#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#include "defs.h"
#include "types.h"

#define DEBUG fprintf(stderr, "#\n");

/*
Mackenzie Craig
Set 2C - A00991048
COMP2510 - Assignment 3

This program uses dynamic memory allocation to sort student records.
*/

int isIDValid(char ID[], char IDDone[]);
int isScoreValid(char tempScore[], int *score);
int isNameValid(char nameHold[], char nameDone[]);

/*
Save a student record
*/
int save(char id[], char nameF[], char nameL[], int *score, saves *list) {

	record newRec;
	name nameStruct;

	strcpy(nameStruct.last, nameL);
	strcpy(nameStruct.first, nameF);

	strcpy(newRec.id, id);

	/* use ptr */
	newRec.grade = *score;

	newRec.name = nameStruct;

	list->save[list->active] = newRec;

	return 0;
}

/*
Take user input
*/
int getInput(saves *list){

	char id[IDSIZE];

	char nameF[NAMESIZE];
	char nameL[NAMESIZE];

	char line[LINESIZE];

	char ID[LINESIZE];
	record *tmp;

	int holder;
	int score;

	char tempFirst[LINESIZE];
	char tempLast[LINESIZE];

	char tempScore[LINESIZE];

	if(!fgets(line, LINESIZE, stdin)){

		fseek(stdin,0,SEEK_END);
		return 0;
	}

	if(sscanf(line, "%s %s %s %s", ID, tempFirst, tempLast, tempScore) == 4) {

		if(isNameValid(tempFirst, nameF) != 1) {
			return 1;
		}

		if(isNameValid(tempLast, nameL) != 1) {
			return 1;
		}

		if(isIDValid(ID, id) != 1) {
			return 1;
		}

		if(isScoreValid(tempScore, &score) != 1) {
			return 1;
		}

		if(list->active == list->nalloc) {
			if(list->nalloc == 0){
				holder = 1;
			}else{
				holder = (list->nalloc * 2);
			}

			tmp = realloc(list->save, holder * sizeof(record));

		  list->nalloc = holder;
			list->save = tmp;

			if(tmp == 0){
				fprintf(stderr, "error");
				return 0;
			}

			DEBUG;
		}

		save(id, nameF, nameL, &score, list);

		/* move to next */
		list->active++;
	}else{
		return 0;
	}
	return 1;
}

/*
Read command line arguments
*/
int parseArguments(char arg[], char firstSort[], char secondSort[]){
	int options = 0;
	options = sscanf(arg, "%2s%2s", firstSort, secondSort);
	return options;
}

/*
Sorts the order of printed students by the sorting flag that is passed.
*/
int sortRecords(char firstSort[], char secondSort[], int sortCode, saves *sortList) {
	if(sortCode > 0) {
		if(((strcmp(firstSort, "n+") == 0)
		&& sortCode == 1)
		|| ((strcmp(firstSort, "n+") == 0)
		&& (strcmp(secondSort, "s+") == 0))){
			qsort(sortList->save, sortList->active, sizeof(record), nameAgradeA);
		} else if(((strcmp(firstSort, "n-") == 0)
		&& (sortCode == 1))
		|| ((strcmp(firstSort, "n-") == 0)
		&& (strcmp(secondSort, "s-") == 0))){
			qsort(sortList->save, sortList->active, sizeof(record), nameDgradeD);
		}


		else if(((strcmp(firstSort, "s+") == 0)
		&& (sortCode == 1))
		|| ((strcmp(firstSort, "s+") == 0)
		&& (strcmp(secondSort, "n+") == 0))){
			qsort(sortList->save, sortList->active, sizeof(record), gradeAnameA);
		} else if(((strcmp(firstSort, "s-") == 0)
		&& (sortCode == 1))
		|| ((strcmp(firstSort, "s-") == 0)
		&& (strcmp(secondSort, "n-") == 0))){
			qsort(sortList->save, sortList->active, sizeof(record), gradeDnameD);
		}


		else if((strcmp(firstSort, "s-") == 0)
		&& (strcmp(secondSort, "n+") == 0)){
			qsort(sortList->save, sortList->active, sizeof(record), gradeAnameD);
		} else if((strcmp(firstSort, "s+") == 0)
		&& (strcmp(secondSort, "n-") == 0)){
			qsort(sortList->save, sortList->active, sizeof(record), gradeDnameA);
		}


		else if((strcmp(firstSort, "n+") == 0)
		&& (strcmp(secondSort, "s-") == 0)){
			qsort(sortList->save, sortList->active, sizeof(record), nameAgradeD);
		} else if((strcmp(firstSort, "n-") == 0)
		&& (strcmp(secondSort, "s+") == 0)){
			qsort(sortList->save, sortList->active, sizeof(record), nameDgradeA);
		}



	} else if(sortCode == 0){
		qsort(sortList->save, sortList->active, sizeof(record), checker);
	} else {
		return 0;
	}

	return 1;

}

/*
Validate a students full name
*/
int isNameValid(char nameHold[], char nameDone[]) {

	int i;

	if(strlen(nameHold) > (NAMESIZE-1)){
		return 0;
	}

	for(i = 0; nameHold[i] != '\0'; i++){
		nameDone[i] = tolower(nameHold[i]);
	}
	nameDone[i] = '\0';

	return 1;
}

/*
Validate a student ID
*/
int isIDValid(char ID[], char IDDone[]) {

	int i;

	if((strlen(ID) >= IDSIZE) || (ID[0] != 'a')) {
		return 0;
	}

	IDDone[0] = 'a';

	for(i = 1; ID[i] != '\0'; i++) {
		if(!isdigit(ID[i])){

			return 0;
		}

		IDDone[i] = ID[i];
	}

	return 1;
}

/*
Validate a score
*/
int isScoreValid(char tempScore[], int *score) {
	int i;

	for(i = 0; tempScore[i] != '\0'; i++){
		if(!isdigit(tempScore[i])){

			return 0;
		}
	}


	sscanf(tempScore, "%d", score);

	if(*score >= 0 && *score <= 100) {
		return 1;
	}

	return 0;
}

/*
Drives the program.
This program uses dynamic memory allocation to sort student records.
*/
int main(int argc, char * argv[]) {

	saves list;

	int options = 1;
	int sortCode = 0;
	int sortedOut = 0;

	size_t i;

	char firstSort[ARGSIZE];
	char secondSort[ARGSIZE];


	record*records = malloc(sizeof(record));

	if(argc != 2 && argc != 1) {
		return 0;
	}

	list.save = records;
	list.nalloc = 0;
	list.active = 0;

	if(argc == 2) {
		sortCode = parseArguments(argv[1], firstSort, secondSort);
	}

	while(options == 1) {
		options = getInput(&list);
	}

	sortedOut = sortRecords(firstSort, secondSort, sortCode, &list);

	/* append here */
	if(sortedOut == 1) {
		for(i = 0; i < list.active; i++) {
			printf("%s : %s, %s : %d\n", list.save[i].id, list.save[i].name.last, list.save[i].name.first, list.save[i].grade);
		}
	}
	free(list.save);

	return 1;
}
