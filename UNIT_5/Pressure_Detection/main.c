#include <stdint.h>
#include <stdio.h>

#include "driver.h"
volatile int pressure = 0;
int main() {
  GPIO_INITIALIZATION();
  
  Set_Alarm_actuator(1);
  while (1) {
	pressure = getPressureVal();
	if (pressure >= 20) {
	  Set_Alarm_actuator(0);
	  Delay(60 * 1000);
	  Set_Alarm_actuator(1);
	}
  }
}