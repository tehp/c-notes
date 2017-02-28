char a[] = "hello";
char *p = "world";
p = &a[i];
printf("%s\n", p);
/* valid, ello */

char a[] = "hello";
char *p = "world";
p[1] = *a;
printf("%s\n", p);
/* invalid, cant change string constant */

char a[] = "hello";
char *p = "world";
a = p;
printf("%s\n", p);
/* invalid, cant assign to an address */
