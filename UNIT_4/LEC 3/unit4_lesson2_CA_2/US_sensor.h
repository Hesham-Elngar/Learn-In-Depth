#ifndef US_SENSOR_H
#define US_SENSOR_H

#include <stdio.h>
#include <stdlib.h>
#include "state.h"

 enum {
    US_busy
} US_state_id;

void US_init();
STATE_DEFINE(US_busy);

extern void (*US_state)();
extern int CA_distance;


#endif // US_SENSOR_H
