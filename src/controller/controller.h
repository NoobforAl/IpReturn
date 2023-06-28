#ifndef CONTROLLER
#define CONTROLLER

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ulfius.h>
#include <arpa/inet.h>

#include "../logger/logger.h"

// Return Requester IP
int callback_ip(
    const struct _u_request *request,
    struct _u_response *response,
    void *_);

#endif