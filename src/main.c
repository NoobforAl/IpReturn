#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ulfius.h>
#include <arpa/inet.h>

#define PORT 8080

int callback_ip(
    const struct _u_request *request,
    struct _u_response *response,
    void *_);

int main(void)
{
    struct _u_instance instance;
    if (ulfius_init_instance(&instance, PORT, NULL, NULL) != U_OK)
    {
        fprintf(stderr, "Error ulfius_init_instance, abort\n");
        return 1;
    }

    ulfius_add_endpoint_by_val(&instance, "*", "*", NULL, 0, &callback_ip, NULL);
    if (ulfius_start_framework(&instance) == U_OK)
    {
        printf("Start framework on port %d\n", instance.port);
        while (getchar() != 'e')
            NULL;
    }
    else
        fprintf(stderr, "Error starting framework\n");

    printf("End framework\n");
    ulfius_stop_framework(&instance);
    ulfius_clean_instance(&instance);
    return 0;
}

int callback_ip(
    const struct _u_request *request,
    struct _u_response *response,
    void *_)
{
    (void)_;
    char log[33];
    char ip[INET_ADDRSTRLEN];

    if (request->client_address->sa_family == AF_INET)
        inet_ntop(AF_INET, &(((struct sockaddr_in *)request->client_address)->sin_addr), ip, INET_ADDRSTRLEN);
    else if (request->client_address->sa_family == AF_INET6)
        inet_ntop(AF_INET6, &(((struct sockaddr_in6 *)request->client_address)->sin6_addr), ip, INET6_ADDRSTRLEN);
    else
        strcpy(ip, "Unknown");

    sprintf(log, "ip: %s request!\n", ip);
    fprintf(stderr, log);

    ulfius_set_string_body_response(response, 200, ip);
    return U_CALLBACK_COMPLETE;
}
