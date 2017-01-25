#define CHECK(PRED)  printf("%s...%s\n", (PRED)?"passed":"failed", #PRED);

int a[] = {3, 2, 7, 6, 8};
CHECK(arr_sum(a, 5) == 26);
