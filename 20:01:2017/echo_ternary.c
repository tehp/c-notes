int main(int argc, char * argvp[]) {
  int i;
  for (i=1; i<argc; i++) {
    printf(i==argc-1 ? "%s\n" : "%s ", argv[i]);
  }
  printf("\n");
  return 0;
}
