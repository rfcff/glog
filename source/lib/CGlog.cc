#include "common.h"
#include "CGlog.h"

using namespace std;

void CGlog::log(const char* fmt, ...)
{
    time_t cur_time;
    struct tm *pCurTm = NULL;

    time(&cur_time);
    pCurTm = localtime(&cur_time);

    struct timeval tv;
    struct timezone tz;
    gettimeofday(&tv, &tz);

    char msg[MAX_LENGTH] = {0};
    sprintf(msg, "[%04d-%02d-%02dT%02d:%02d:%02d.%03d]",
            pCurTm->tm_year + 1900, pCurTm->tm_mon + 1, pCurTm->tm_mday,
            pCurTm->tm_hour, pCurTm->tm_min, pCurTm->tm_sec, (unsigned int)(tv.tv_usec/1000));

    va_list ap;
    va_start(ap, fmt);
    vsnprintf(msg + strlen(msg), sizeof(msg) - strlen(msg) - 1, fmt, ap);
    va_end(ap);
    cout<<msg<<endl;
}

void CGlog::log(const char* hint, int line, const char* fmt, ...)
{
    time_t cur_time;
    struct tm *pCurTm = NULL;

    time(&cur_time);
    pCurTm = localtime(&cur_time);

    struct timeval tv;
    struct timezone tz;
    gettimeofday(&tv, &tz);

    char msg[MAX_LENGTH] = {0};
    sprintf(msg, "[%s:%d %04d-%02d-%02dT%02d:%02d:%02d.%03d]", hint, line,
            pCurTm->tm_year + 1900, pCurTm->tm_mon + 1, pCurTm->tm_mday,
            pCurTm->tm_hour, pCurTm->tm_min, pCurTm->tm_sec, (unsigned int)(tv.tv_usec/1000));

    va_list ap;
    va_start(ap, fmt);
    vsnprintf(msg + strlen(msg), sizeof(msg) - strlen(msg) - 1, fmt, ap);
    va_end(ap);
    cout<<msg<<endl;
}

