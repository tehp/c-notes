int n = 1; /* external variable: lifetime is duration of program */
int main(void) {
  if (...) {
    int x = 2;
  } /* x destroyed here */
}
