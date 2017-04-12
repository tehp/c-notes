/*
Do below lines if TYPES_H is not defined.
*/
#ifndef TYPES_H
#define TYPES_H

#define IDSIZE 10
#define NAMESIZE 20

#define LINESIZE 256
#define ARGSIZE 3

/*
Structs used in this program
*/

typedef struct{
	char  first[NAMESIZE];
	char  last[NAMESIZE];
} name;

typedef struct{
	name  name;
	char  id[IDSIZE];
	int   grade;
} record;

typedef struct{
	record  *save;
	size_t   nalloc;
	size_t   active;
} saves;
#endif
