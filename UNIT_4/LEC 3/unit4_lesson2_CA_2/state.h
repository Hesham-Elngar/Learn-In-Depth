#ifndef STATE_H
#define STATE_H

// Macro to define state function
#define STATE_DEFINE(stateFunc_) void ST_##stateFunc_()
#define STATE(stateFunc_) ST_##stateFunc_

// Function declarations
void US_get_distance(int distance);
void DC_motor(int speed);

#endif // STATE_H
