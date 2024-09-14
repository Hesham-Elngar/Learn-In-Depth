/*
 * lcd_config.h
 *
 *  Created on: Aug 5, 2024
 *      Author: super magic
 */

#ifndef HAL_LAYER_LCD_LCD_CONFIG_H_
#define HAL_LAYER_LCD_LCD_CONFIG_H_

#include "stm32f103x6"
#include "Gpio.h"

#define LCD_RS_PORT           GPIOA
#define LCD_RS_PIN            GPIO_PIN8

#define LCD_RW_PORT           GPIOA
#define LCD_RW_PIN            GPIO_PIN9

#define LCD_EN_PORT           GPIOA
#define LCD_EN_PIN            GPIO_PIN10

#define LCD_8_BIT_MODE  	1
#define LCD_4_BIT_MODE  	2

#define LCD_MODE LCD_8_BIT_MODE

#if LCD_MODE == LCD_8_BIT_MODE
#define LCD_D0_PORT            GPIOA
#define LCD_D0_PIN             GPIO_PIN0

#define LCD_D1_PORT            GPIOA
#define LCD_D1_PIN             GPIO_PIN1

#define LCD_D2_PORT            GPIOA
#define LCD_D2_PIN             GPIO_PIN2

#define LCD_D3_PORT            GPIOA
#define LCD_D3_PIN             GPIO_PIN3
#endif

#define LCD_D4_PORT            GPIOA
#define LCD_D4_PIN             GPIO_PIN4

#define LCD_D5_PORT            GPIOA
#define LCD_D5_PIN             GPIO_PIN5

#define LCD_D6_PORT            GPIOA
#define LCD_D6_PIN             GPIO_PIN6

#define LCD_D7_PORT            GPIOA
#define LCD_D7_PIN             GPIO_PIN7

#endif /* HAL_LAYER_LCD_LCD_CONFIG_H_ */
