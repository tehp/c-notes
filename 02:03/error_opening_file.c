#include <errno.h>
fprinf(stderr, "fopen %s: %s\n", argv[1], strerror(errno));
