int a[10];
printf("%d", a == &a[0]);
/* prints 1 */


p = &a[0];
p = a; /* also okay */
