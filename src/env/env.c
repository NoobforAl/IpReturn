#include "env.h"

// get debug mod run
bool getDebug(void)
{
    char *debug = getenv("DEBUG");
    return !strcmp(debug, "true") || !strcmp(debug, "TRUE");
}