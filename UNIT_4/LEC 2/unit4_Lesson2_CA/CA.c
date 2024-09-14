#include "CA.h"

int CA_speed = 0;
int CA_distance = 0;
int CA_threshold = 50;

void (*CA_state)() = STATE(CA_waiting);

void DisplaySpeed_GetDistance()
{
    printf("Speed is = %d ,", CA_speed);
    CA_distance = 45 + rand()%11; //get random value from 45:55
    printf("Distance = %d\n",CA_distance);
}

STATE_DEFINE(CA_waiting) {
    CA_speed = 0;
    while (CA_distance <= CA_threshold) {
        DisplaySpeed_GetDistance();
    }
    CA_state = STATE(CA_driving);
}

STATE_DEFINE(CA_driving) {
    CA_speed = 30;
    while (CA_distance > CA_threshold) {
        DisplaySpeed_GetDistance();
    }
    CA_state = STATE(CA_waiting);
}


