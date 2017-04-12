#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "types.h"

/*
Prepare sorting flags
*/
int checker(const void *firstToCheck, const void *secondToCheck){

    record *r1 = (record *)firstToCheck;
    record *r2 = (record *)secondToCheck;

    if(strcmp(r1->id, r2->id) > 0){

    	return -1;
    }else if(strcmp(r1->id, r2->id) < 0){

    	return 1;
    }

    return 0;
}

/*
FOR ALL METHODS BELOW:
A: ascending
D: descending

eg. gradeAnameD = grade ascending, name descending
*/

int gradeAnameA(const void *firstToCheck, const void *secondToCheck){

    record *r1 = (record *)firstToCheck;
    record *r2 = (record *)secondToCheck;

    if((r1->grade - r2->grade) > 0) {
    	return 1;
    }
    if((r1->grade - r2->grade) < 0) {
    	return -1;
    }


    if(strcmp(r1->name.last, r2->name.last) > 0) {
    	return -1;
    }
    if(strcmp(r1->name.last, r2->name.last) < 0) {
    	return 1;
    }


    if(strcmp(r1->name.first, r2->name.first) > 0) {
    	return -1;
    }
    if(strcmp(r1->name.first, r2->name.first) < 0) {
    	return 1;
    }

    return 0;
}

int gradeDnameD (const void *firstToCheck, const void *secondToCheck) {

    record *r1 = (record *)firstToCheck;
    record *r2 = (record *)secondToCheck;

    if(r1->grade - r2->grade > 0) {
    	return -1;
    }

    if(r1->grade - r2->grade < 0) {
    	return 1;
    }

    if(strcmp(r1->name.first, r2->name.first) > 0) {
    	return 1;
    }

    if(strcmp(r1->name.first, r2->name.first) < 0) {
    	return -1;
    }

    if(strcmp(r1->name.last, r2->name.last) > 0) {
    	return 1;
    }

    if(strcmp(r1->name.last, r2->name.last) < 0) {
    	return -1;
    }

    return (r1->grade - r2->grade);
}

int gradeAnameD(const void *firstToCheck, const void *secondToCheck) {

    record *r1 = (record *)firstToCheck;
    record *r2 = (record *)secondToCheck;

    if(r1->grade - r2->grade < 0) {
    	return -1;
    }

    if(r1->grade - r2->grade > 0) {
    	return 1;
    }

    if(strcmp(r1->name.last, r2->name.last) > 0) {
    	return 1;
    }

    if(strcmp(r1->name.first, r2->name.first) > 0) {
    	return 1;
    }

    if(strcmp(r1->name.first, r2->name.first) < 0) {
    	return -1;
    }

    if(strcmp(r1->name.last, r2->name.last) < 0) {
    	return -1;
    }

    return ( r1->grade - r2->grade );
}

int gradeDnameA(const void *firstToCheck, const void *secondToCheck) {

    record *r1 = (record *)firstToCheck;
    record *r2 = (record *)secondToCheck;

    if(r1->grade - r2->grade > 0) {
    	return -1;
    }else if(r1->grade - r2->grade < 0) {
    	return 1;
    }

    if(strcmp(r1->name.last, r2->name.last) > 0) {
    	return -1;
    }else if(strcmp(r1->name.last, r2->name.last) < 0) {
    	return 1;
    }

    if(strcmp(r1->name.first, r2->name.first) > 0) {
    	return -1;
    }else if(strcmp(r1->name.first, r2->name.first) < 0) {
    	return 1;
    }

    return ( r1->grade - r2->grade );
}

int nameDgradeA(const void *firstToCheck, const void *secondToCheck) {

    record *r1 = (record *)firstToCheck;
    record *r2 = (record *)secondToCheck;

    if(strcmp(r1->name.last, r2->name.last) > 0) {
    	return 1;
    }else if(strcmp(r1->name.last, r2->name.last) < 0) {
    	return -1;
    }

    if(strcmp(r1->name.first, r2->name.first) > 0) {
    	return 1;
    }else if(strcmp(r1->name.first, r2->name.first) < 0) {
    	return -1;
    }

    if(r1->grade - r2->grade > 0) {
    	return 1;
    }else if(r1->grade - r2->grade < 0) {
    	return -1;
    }

    return 0;
}

int nameAgradeD(const void *firstToCheck, const void *secondToCheck) {

	  record *r1 = (record *)firstToCheck;
    record *r2 = (record *)secondToCheck;

    if(strcmp(r1->name.last, r2->name.last) > 0) {
    	return -1;
    }else if(strcmp(r1->name.last, r2->name.last) < 0) {
    	return 1;
    }

    if(strcmp(r1->name.first, r2->name.first) > 0) {
    	return -1;
    }else if(strcmp(r1->name.first, r2->name.first) < 0) {
    	return 1;
    }

    if(r1->grade - r2->grade > 0) {
    	return -1;
    }else if(r1->grade - r2->grade < 0) {
    	return 1;
    }

    return 0;
}

int nameAgradeA(const void *firstToCheck, const void *secondToCheck) {

	  record *r1 = (record *)firstToCheck;
    record *r2 = (record *)secondToCheck;

    if(strcmp(r1->name.last, r2->name.last) > 0) {
    	return -1;
    }else if(strcmp(r1->name.last, r2->name.last) < 0) {
    	return 1;
    }

    if(strcmp(r1->name.first, r2->name.first) > 0) {
    	return -1;
    }else if(strcmp(r1->name.first, r2->name.first) < 0) {
    	return 1;
    }

    if(r1->grade - r2->grade > 0) {
    	return 1;
    }else if(r1->grade - r2->grade < 0) {
    	return -1;
    }

    return 0;
}

int nameDgradeD(const void *firstToCheck, const void *secondToCheck){

	  record *r1 = (record *)firstToCheck;
    record *r2 = (record *)secondToCheck;

    if(strcmp(r1->name.last, r2->name.last) > 0){
    	return 1;
    }else if(strcmp(r1->name.last, r2->name.last) < 0){
    	return -1;
    }

    if(strcmp(r1->name.first, r2->name.first) > 0){
    	return 1;
    }else if(strcmp(r1->name.first, r2->name.first) < 0){
    	return -1;
    }

    if(r1->grade - r2->grade > 0){
    	return -1;
    }else if(r1->grade - r2->grade < 0){
    	return 1;
    }

    return 0;
}
