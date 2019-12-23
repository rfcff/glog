#include <stdarg.h>
#include <string.h>
#include <time.h>
#include <sys/time.h>

typedef enum log_level
{
	LogVerbose = 0;
	LogDebug = 1;
	LogInfo = 2;
	LogCritical = 3;
}LogLevel;

class CGlog{
public:
    static void log(const char* fmt, ...);
    static void log(const char* hint, int line, const char* fmt, ...);
};

