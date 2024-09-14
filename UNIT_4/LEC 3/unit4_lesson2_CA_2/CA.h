#ifndef CA_H
#define CA_H

#include <stdio.h>
#include <stdlib.h>
#include "state.h"

// Enum for state IDs
enum {
    CA_waiting,
    CA_driving
} CA_state_id;

// Function prototypes for state functions
STATE_DEFINE(CA_waiting);
STATE_DEFINE(CA_driving);

// Extern declarations for global variables and function pointers
extern void (*CA_state)();

#endif // CA_H
