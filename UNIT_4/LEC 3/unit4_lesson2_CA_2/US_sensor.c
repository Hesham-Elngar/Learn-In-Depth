#include "US_sensor.h"

int US_distance = 0;

void (*US_state)() = STATE(US_busy);

void US_init()
{
    printf("US_init....\n");
}

int US_set_distance()
{
    return 45 + rand()%11; //get random value from 45:55
}

STATE_DEFINE(US_busy) {
    US_state_id = US_busy;
    int d = US_set_distance();
    printf("US_waiting state:\tdistance=%d\n",d);
    US_get_distance(d);
}
