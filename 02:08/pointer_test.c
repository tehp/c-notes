int m = 1, n = 2;
int *p = &m, *q = &n;
*p = *q + 1; /* same as: m = n+ 1 */
*q = *p = 2; /* same as: n = m - 2 */
printf("%d%d", m, n);


int m = 1, n = 2;
int *p = &m, *q = &n;
*p = *q + 1;
p = q;
*p = *q + 3;
printf("%d%d", m, n);
