struct Score a[10], *p;

a[0].score = 78;

strcpy(a[0].id, "a222222222");

a[1] = a[0]; /* Assignment of structs */

p = &a[1]; /* Make p point to a[1] */

printf("%d\n", (*p).score);

/* *p.score = *(p.score) */
