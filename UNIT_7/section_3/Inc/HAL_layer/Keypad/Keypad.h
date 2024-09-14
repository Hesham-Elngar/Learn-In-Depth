/*
 * Keypad.h
 *
 *  Created on: Aug 5, 2024
 *      Author: super magic
 */

#ifndef HAL_LAYER_KEYPAD_KEYPAD_H_
#define HAL_LAYER_KEYPAD_KEYPAD_H_

#include "GPIO.h"

#define R0_PORT  GPIOB
#define R0_PIN   GPIO_PIN0

#define R1_PORT  GPIOB
#define R1_PIN   GPIO_PIN1

#define R2_PORT  GPIOB
#define R2_PIN   GPIO_PIN2

#define R3_PORT  GPIOB
#define R3_PIN   GPIO_PIN3

#define C0_PORT   GPIOB
#define C0_PIN    GPIO_PIN4

#define C1_PORT   GPIOB
#define C1_PIN    GPIO_PIN5

#define C2_PORT   GPIOB
#define C2_PIN    GPIO_PIN6

#define C3_PORT   GPIOB
#define C3_PIN    GPIO_PIN7

/*NUMBER OF ROWS AND COLUMS*/
#define  KEYPAD_ROWS   4
#define  KEYPAD_COLUMS 4

void HAL_KEYPAD_INIT(void);
char HAL_KEYPAD_GET_KEY(void);

#endif /* HAL_LAYER_KEYPAD_KEYPAD_H_ */
