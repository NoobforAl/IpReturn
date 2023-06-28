#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>
#include <ulfius.h>
#include <arpa/inet.h>

#include "env/env.h"
#include "router/router.h"
#include "logger/logger.h"

// ulfius app
struct _u_instance ins;

// handle signal error
void sigtermHandler(int signum);

// start frame work
int startFrameWork(void);

// clean app frame work
void cleanProgram(void);

int main(void)
{
    // handle exit from program
    signal(SIGTERM, sigtermHandler);
    signal(SIGINT, sigtermHandler);

    // init logger
    initLogger(getDebug());

    int exit = startFrameWork();
    cleanProgram();
    return exit;
}

void sigtermHandler(int signum)
{
    warn("Received SIGTERM signal. Performing cleanup...\n");
    warn("End framework\n");
    cleanProgram();
    exit(signum);
}

int startFrameWork(void)
{
    // setUp Port 8080
    if (ulfius_init_instance(&ins, 8080, NULL, NULL) != U_OK)
    {
        error("Error ulfius_init_instance, abort\n");
        return 1;
    }

    setRouter(&ins);
    if (ulfius_start_framework(&ins) == U_OK)
    {
        info("Start framework on port 8080\n");
        while (getchar() != 'e')
            NULL;
    }
    else
        error("Error starting framework\n");

    return 0;
}

void cleanProgram(void)
{
    ulfius_stop_framework(&ins);
    ulfius_clean_instance(&ins);
}