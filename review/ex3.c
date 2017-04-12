#include <stdio.h>

int q1a() {

  int a = 0;
  int b = 0;
  int c = -1;

  printf("\n%s\n", "q1a ------");

  c = a++ || ++b;

  printf("%d %d %d\n", a, b, c);

  return 1;
}

int q1b() {
  int a = 1;
  int b = 1;
  int c = -1;

  printf("\n%s\n", "q1b ------");

  c = --a && b++;

  printf("%d %d %d\n", a, b, c);

  return 1;
}

int q1c() {
  int n = 3;
  int *p = &n;

  printf("\n%s\n", "q1c ------");

  while (++*p < 8) {
    printf("%d\n", *p);
  }

  return 1;
}

int q1d() {
  int a[] = {5,3,1};
  int *p = &a[1];

  printf("\n%s\n", "q1d ------");

  printf("%d\n", *p--);
  printf("%d\n", *p);

  return 1;
}

int q1e() {
  int a[] = {5,3,1};
  int *p = &a[1];

  printf("\n%s\n", "q1e ------");

  printf("%d\n", --*p);
  printf("%d\n", *p);

  return 1;
}

int q1f() {
  int a[] = {9,8,7,6,5,4,3,2,1};
  int *p = a + 1;

  printf("\n%s\n", "q1f ------");

  while (*p++ > 5) {
    printf("%d\n", *p);
  }

  return 1;
}

int q1g() {
  int a[] = {12,10,8,6,4,3,2,1};
  int *p = a + 1;

  printf("\n%s\n", "q1g ------");

  while (--*p > 5) {
    printf("%d\n", *p);
  }

  return 1;
}

int q1h() {
  int a[] = {1,2,3,4,5,6,7,8,9};
  int *p;

  printf("\n%s\n", "q1h ------");

  for (p=a+1; p<a+8; p+=2) {
    printf("%d\n", *p);
  }

  return 1;
}

int q1i() {
  int m = 12;
  int n = 34;
  int *p = &m;
  int *q = &n;

  *q = --*p;
  *p = (*q)--;

  printf("\n%s\n", "q1i ------");

  printf("%d %d\n", *p, *q);

  return 1;
}

int q1j() {
  int a[] = {11,22};
  int *p = a;
  int *q = a+1;

  printf("\n%s\n", "q1j ------");

  p++;
  q++;

  printf("%d %d\n", *p, *q);

  return 1;
}

int q1k() {
  char a[] = "goodbye!";
  char *p;

  printf("\n%s\n", "q1k ------");

  for (p=a; *p!=0; p+=2) {
    putchar(*p);
  }
  printf("\n");

  return 1;
}

int q1l() {
  int a[] = {11,22,33};
  int *b[3];
  int **p, **q, **r;

  b[0] = a;
  b[1] = a+1;
  b[2] = a+2;

  p = b;
  q = b+1;
  r = b+2;

  *p = *r--;
  --*q;

  printf("\n%s\n", "q1l ------");

  printf("%d %d %d\n",**p, **q, **r);

  return 1;
}

int q1m() {
  int a[] = {11, 22, 33};
  int *p = a;
  int *q = a+1;
  int *r = a+2;

  *p++ = *r--;
  *++q = *r--;

  --*p;
  ++*q;
  --*r;

  printf("\n%s\n", "q1m ------");

  printf("%d %d %d\n", a[0], a[1], a[2]);

  return 1;
}

int q1n() {
  char a[32] = "0123456789";

  printf("\n%s\n", "q1n ------");

  sscanf("hi", "%s", a+4);
  printf("%s\n", a+2);

  return 1;
}

int q1o() {
  char *argv[] = {"hello", "beautiful", "world"};

  printf("\n%s\n", "q1k ------");

  printf("%s\n", *(argv+1));

  return 1;
}

int q1p() {
  char *argv[] = {"hello", "beautiful", "world"};

  printf("\n%s\n", "q1p ------");

  printf("%s\n", *argv+1);

  return 1;
}

int main(void) {
  printf("%s\n", "------ QUESTION 1 ------");
  q1a();
  q1b();
  q1c();
  q1d();
  q1e();
  q1f();
  q1g();
  q1h();
  q1i();
  q1j();
  q1k();
  q1l();
  q1m();
  q1n();
  q1o();
  q1p();
}
