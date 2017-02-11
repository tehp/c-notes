char s[] = "hello";
char *p = "world";

char s[] = "hello";
char *s = "hello";

printf("%s", s);

p = s;
s = p;

s[0] = p[0];
p[0] = s[0];
