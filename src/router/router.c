#include "router.h"

void setRouter(struct _u_instance *ins)
{
    debug("setup all path");

    // return ip user
    // only do this!
    // path is * this mean
    // request all response
    // with different path!
    ulfius_add_endpoint_by_val(ins, "*", "*", NULL, 0, &callback_ip, NULL);
}
