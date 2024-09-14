#include "DC.h"

int DC_speed = 0;


void (*DC_state)();


void DC_init()
{
    // set_pwm();
    printf("DC_init...\n");
}

void DC_motor(int speed)
{
   DC_speed = speed;
   DC_state = STATE(DC_busy);
   printf("CA-----speed=%d----->DC\n",speed);
}

STATE_DEFINE(DC_idle) {
    DC_speed = 0;
    DC_state_id = DC_idle;
    printf("DC_idle state:\tspeed=%d\n",DC_speed);
}

STATE_DEFINE(DC_busy) {
    DC_speed = 30;
    DC_state_id = DC_busy;
    printf("DC_busy state:\tspeed=%d\n",DC_speed);
}


