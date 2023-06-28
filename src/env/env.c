#include "env.h"

// get debug mod run
bool getDebug(void)
{
    char *debug = getenv("DEBUG_IP_RETURN");
    char *_true = "true";
    char *_TRUE = "TRUE";

    return debug != NULL &&
           (!strcmp(debug, _true) ||
            !strcmp(debug, _TRUE));
}