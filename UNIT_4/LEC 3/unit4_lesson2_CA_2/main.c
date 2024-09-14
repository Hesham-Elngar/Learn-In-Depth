#include"US_sensor.h"
#include"CA.h"
#include"DC.h"

void setup()
{
    US_init();
    DC_init();
    CA_state = STATE(CA_waiting);
    DC_state = STATE(DC_idle);
    US_state = STATE(US_busy);
}
int main()
{
    setup();
    for(int i=0; i<10; ++i)
    {
            US_state();
          CA_state();
            DC_state();

    }

    return 0;
}
