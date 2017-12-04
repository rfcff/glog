#include <stdarg.h>
#include <string.h>
#include <time.h>
#include <sys/time.h>

class CGlog{
public:
    static void log(const char* fmt, ...);
    static void log(const char* hint, int line, const char* fmt, ...);
};

