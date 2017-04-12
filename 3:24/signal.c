void (* signal(int, void(*)(int)))(int);

typedef void(* sighandler_t)(int);
sighandler_t signal(int, sighandler_t);

void qsort(void *, size_t, size_t, int (*)(const void *, const void *));
