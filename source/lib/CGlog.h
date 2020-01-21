#include <stdarg.h>
#include <string.h>
#include <time.h>
#include <sys/time.h>

typedef enum log_level
{
	kLogVerbose = 0;
	kLogDebug = 1;
	kLogInfo = 2;
	kLogWarning = 3;
	kLogCritical = 4;
}LogLevel;

class CGlog{
 public:
    static void log(const char* fmt, ...);
    static void log(const char* hint, int line, const char* fmt, ...);
};

