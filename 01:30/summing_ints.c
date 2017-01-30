#define LINESIZE 1024;

int n, sum = 0;
char line[LINESIZE];
while(1) {
  printf("Enter an int: ");
  if (!fgets(line, LINESIZE, stdin)) {
    clearerr (stdin);
    break;
  }
  if (sscanf(line, "%d", &n) == 1) {
    sum += n;
  }
}
printf("%d\n", sum);
