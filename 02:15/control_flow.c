if (argc == 1) {
  ...
} else if (argc == 2) {
  ...
} else {
  ...
}

char choice = get_choice();
  switch(choice) {
    case'y':case'Y':
      ...
      break;
    case'n':case'N':
      ...
      break;
    default:
      ...
  }



int n = 1;
while (n++ < 5) {
  printf("%d\n", n);
}
/* 2, 3, 4, 5 */

int n = 1;
while (n < 5) {
  printf("%d\n", ++n);
}
/* 2, 3, 4, 5 */

int n = 1;
while (++n < 5) {
  printf("%d\n", n);
}
/* 2, 3, 4 */

int n = 1;
while (n < 5) {
  printf("%d\n", n++);
}
/* 1, 2, 3, 4 */


do {
  ...
} while (...);

for (initialization; test; update) {
  ...
}

for (i=0; i<10; i++) {
  printf("%d", i*i);
}

while (...) {
  ...
  if (...) {
    continue;
    ...
  }
  if (...) {
    break;
    ...
  }
  /* continue goes to here */
}
/* break goes to here */
