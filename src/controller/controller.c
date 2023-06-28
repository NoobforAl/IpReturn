#include "controller.h"

static char *parsIP(const struct _u_request *req)
{
    char *ip = (char *)malloc(sizeof(char) * 17);
    if (req->client_address->sa_family == AF_INET)
        inet_ntop(AF_INET, &(((struct sockaddr_in *)req->client_address)->sin_addr), ip, INET_ADDRSTRLEN);
    else if (req->client_address->sa_family == AF_INET6)
        inet_ntop(AF_INET6, &(((struct sockaddr_in6 *)req->client_address)->sin6_addr), ip, INET6_ADDRSTRLEN);
    else
        strcpy(ip, "Unknown");

    return ip;
}

int callback_ip(
    const struct _u_request *req,
    struct _u_response *res,
    void *_)
{
    (void)_;

    debug("Get New Request Pars IP\n");
    char *ip = parsIP(req);
    char log[33];

    ulfius_set_string_body_response(res, 200, ip);
    sprintf(log, "%s request!\n", ip);
    info(log);
    free(ip);

    return U_CALLBACK_COMPLETE;
}