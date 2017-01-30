int a[100];
size_t n;
n = fread(a, sizeof(a[0]), 100, fp);

fwrite(a, sizeof(a[0]), 100, fp); 
