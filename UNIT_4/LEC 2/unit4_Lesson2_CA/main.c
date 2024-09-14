
#include"CA.h"
#define THRESHOLD 50
volatile int i=0;
int main()
{
    printf("Hello !\n");
    CA_distance = 45 + rand()%11; //get random value from 45:55
    CA_state = CA_distance> THRESHOLD ? STATE(CA_driving):STATE(CA_waiting);
    while(1)
    {
        CA_state();
        for(i=0;i<10000;++i);
    }

    return 0;
}
