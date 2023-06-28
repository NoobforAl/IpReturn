#include "logger.h"

bool DEBUG;

static char *getNowTime(void)
{
    time_t currentTime;
    struct tm *timeInfo;
    char *formattedTime = (char *)malloc(sizeof(char) * 20);

    time(&currentTime);
    timeInfo = localtime(&currentTime);

    // Format the time as "YYYY/MM/DD HH:MM:SS"
    strftime(formattedTime, 20, "%Y/%m/%d %H:%M:%S", timeInfo);

    // free(timeInfo);
    return formattedTime;
}

static void printLogger(const char *format, const char *msg)
{
    char *t = getNowTime();
    fprintf(stderr, format, t, msg);
    free(t);
}

void initLogger(const bool de)
{
    if (!de)
        return;

    DEBUG = de;
    debug("app run debug mode");
}

void info(const char *msg)
{
    printLogger(INFO_MSG, msg);
}

void warn(const char *msg)
{
    printLogger(WARN_MSG, msg);
}

void debug(const char *msg)
{
    if (DEBUG)
        printLogger(DEBUG_MSG, msg);
}

void error(const char *msg)
{
    printLogger(ERROR_MSG, msg);
}
