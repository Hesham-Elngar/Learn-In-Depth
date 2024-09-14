/*
 * Gpio.h
 *
 *  Created on: Aug 5, 2024
 *      Author: super magic
 */

#ifndef MCAL_LAYER_GPIO_GPIO_H_
#define MCAL_LAYER_GPIO_GPIO_H_

#include "stm32f103x6"

#define GPIO_PIN0  0
#define GPIO_PIN1  1
#define GPIO_PIN2  2
#define GPIO_PIN3  3
#define GPIO_PIN4  4
#define GPIO_PIN5  5
#define GPIO_PIN6  6
#define GPIO_PIN7  7
#define GPIO_PIN8  8
#define GPIO_PIN9  9
#define GPIO_PIN10 10
#define GPIO_PIN11 11
#define GPIO_PIN12 12
#define GPIO_PIN13 13
#define GPIO_PIN14 14
#define GPIO_PIN15 15

#define GPIO_INPUT_Analog 		    	   0
#define GPIO_INPUT_Floating 	 		   1
#define GPIO_INPUT_Analog_PU 			   2
#define GPIO_INPUT_Analog_PD 			   3
#define GPIO_OUTPUT_Push_Pull  			   4
#define GPIO_OUTPUT_Open_Drain 			   5
#define GPIO_OUTPUT_Alternate_Push_Pull    6
#define GPIO_OUTPUT_Alternate_Open_Drain   7
#define GPIO_INTPUT_Alternate			   8


#define GPIO_OUTPUT_MODE_2MHz		1
#define GPIO_OUTPUT_MODE_10MHz		2
#define GPIO_OUTPUT_MODE_50MHz		3

#define GPIO_PIN_SET   1
#define GPIO_PIN_RESET 0

#define GPIO_PIN_RETURN_LOCK_ENABLE 1
#define GPIO_PIN_RETUN_LOCK_DISABLE 0

#define SET_BIT(REG,BIT)  (REG|=(1<<BIT))
#define READ_BIT(REG,BIT) ((REG&(1<<BIT))>>BIT)
#define CLR_BIT(REG,BIT)  (REG&=~(1<<(BIT)))
#define TOG_BIT(REG,BIT)  (REG^=(1<<(BIT)))

#define LCD_DELAY_LONG  1000
#define LCD_DELAY_SHORT 100


typedef struct{
	uint16_t pinNumber;
	uint8_t output_speed;
	uint8_t mode;
}Gpio_PinConfig_t;

void MCAL_Gpio_Init(Gpio_typedef* Gpiox ,Gpio_PinConfig_t* pin);
void MCAL_Gpio_DeInit(Gpio_typedef* Gpiox);

uint8_t MCAL_Gpio_ReadPin(Gpio_typedef* Gpiox ,uint16_t pin);
void MCAL_Gpio_WritePin(Gpio_typedef* Gpiox ,uint16_t pin,uint8_t value);
void MCAL_Gpio_TogglePin(Gpio_typedef* Gpiox ,uint16_t pin);
void MCAL_Gpio_LockPin(Gpio_typedef* Gpiox ,uint16_t pin);

uint16_t MCAL_Gpio_ReadPort(Gpio_typedef* Gpiox);
void MCAL_Gpio_WritePort(Gpio_typedef* Gpiox ,uint16_t value);

#endif /* MCAL_LAYER_GPIO_GPIO_H_ */
