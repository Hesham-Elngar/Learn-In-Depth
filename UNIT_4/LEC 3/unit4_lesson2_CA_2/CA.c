#include "CA.h"

int CA_speed = 0;
int CA_distance = 0;
int CA_threshold = 50;

// Function pointer for the current state
void (*CA_state)();  // Initialize to CA_waiting state

void US_get_distance(int distance)
{
    CA_distance = distance;
    CA_state = CA_distance > CA_threshold ? STATE(CA_driving) : STATE(CA_waiting);
    printf("US -------Distance=%d-------> CA\n", CA_distance);
}

STATE_DEFINE(CA_waiting) {
    CA_state_id = CA_waiting;
    CA_speed = 0;
    printf("CA waiting state: distance=%d   speed=%d\n", CA_distance, CA_speed);
    DC_motor(CA_speed);
}

STATE_DEFINE(CA_driving) {
    CA_state_id = CA_driving;
    printf("CA driving state: distance=%d   speed=%d\n", CA_distance, CA_speed);
    CA_speed = 30;
    DC_motor(CA_speed);
}
