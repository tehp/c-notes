fseek(fp, -5, SEEK_CUR);

if (fseek(fp, n, SEEK_CUR) == 1) {
  /* seek error */
  perror("fseek");
}


long pos = ftell(fp);
if (pos == -1) {
  perror("ftell");
  /* additional error handling */
}

fflush(fp);
