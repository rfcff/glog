#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <fcntl.h>
#include <unistd.h>
#include <ctype.h>
#include <errno.h>
#include <inttypes.h>

#include <string.h>
#include <string>
#include <iostream>

#include <time.h>   /* about time */

// about network
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <sys/time.h>

// about signal
#include <signal.h>
typedef void Sigfunc(int);  /* signal handlers */

// about pthread
#include <pthread.h>
// semaphore
#include <semaphore.h>

#define max(a, b)   (a) < (b) ? (b) : (a)
#define min(a, b)   (a) < (b) ? (a) : (b)
#define SAFE_DELETE(res) do { \
							if (NULL != res) { \
								delete res; \
								res = NULL; \
							} \
						} while(0)
#define SAFE_FREE(res)	do {\
							if (NULL != res) { \
								free(res); \
								res = NULL; \
							} \
						} while(0)

#define MAX_LENGTH  4096

