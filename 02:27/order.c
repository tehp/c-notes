int a = 1, b = 0, c = 2;
c = --a && ++b;
printf("%d%d%d\n", a, b, c);

int a = 1, b = 0, c = 2
c = a-- && ++b;
printf("%d%d%d\n", a, b, c);

int a = 1, b = 0, c = 2;
c = --a || ++b;

int a = 1, b = 0, c = 2;
c = a-- || ++b;
