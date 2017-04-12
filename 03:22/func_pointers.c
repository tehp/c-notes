int add(int, int);

int minus(int, int);

int multiply(int, int);

int divide(int, int);

int (*ops[4])(int, int);

ops[0] = add;
ops[1] = minus;

int (*ops[])(int, int) = {add, minus, multiply, divide};


printf("%d\n", (*ops[1])(2, 3));
