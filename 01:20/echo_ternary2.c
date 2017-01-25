int main(int argc, char * argvp[]) {
  int i;
  for (i=1; i<argc; i++) {
    printf("%s%c", argv[i], i==argc-1 ? '\n' : ' ');
  }
  printf("\n");
  return 0;
}
