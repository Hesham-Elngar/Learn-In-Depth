#ifndef DC_H
#define DC_H
#include <stdio.h>
#include <stdlib.h>
#include "state.h"

enum {
    DC_idle,
    DC_busy,
} DC_state_id;

void DC_init();
STATE_DEFINE(DC_idle);
STATE_DEFINE(DC_busy);

extern void (*DC_state)();



#endif // DC_H
