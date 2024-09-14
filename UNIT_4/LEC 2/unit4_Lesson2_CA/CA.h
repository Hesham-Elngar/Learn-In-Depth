#ifndef CA_H
#define CA_H
#include <stdio.h>
#include <stdlib.h>
#include "state.h"

typedef enum {
    CA_waiting,
    CA_driving
} CA_state_id;

STATE_DEFINE(CA_waiting);
STATE_DEFINE(CA_driving);
void DisplaySpeed_GetDistance();
extern void (*CA_state)();
extern int CA_distance;

#endif // CA_H
