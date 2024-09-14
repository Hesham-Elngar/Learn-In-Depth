/*
 * Keypad.c
 *
 *  Created on: Aug 5, 2024
 *      Author: super magic
 */


#include "HAL_layer/Keypad/Keypad.h"

Gpio_PinConfig_t pinconfg;

uint16_t KEYPAD_ROW_PIN[KEYPAD_ROWS] = {R0_PIN, R1_PIN, R2_PIN, R3_PIN};
Gpio_typedef * KEYPAD_ROW_PORT[KEYPAD_ROWS] = {R0_PORT, R1_PORT, R2_PORT, R3_PORT};
uint16_t KEYPAD_COL_PIN[KEYPAD_COLUMS] = {C0_PIN, C1_PIN, C2_PIN, C3_PIN};
Gpio_typedef * KEYPAD_COL_PORT[KEYPAD_COLUMS] = {C0_PORT, C1_PORT, C2_PORT, C3_PORT};

uint8_t KEYPAD_keys[KEYPAD_ROWS][KEYPAD_COLUMS] = {
		{'7','8','9','/'},
		{'4','5','6','*'},
		{'1','2','3','-'},
		{'C','0','=','+'}
};

void HAL_KEYPAD_INIT(void) {
	Gpio_PinConfig_t PinConfig;

	// Initialize rows as input with pull-up resistors
	PinConfig.pinNumber = R0_PIN;
	PinConfig.mode = GPIO_INPUT_Analog_PU;
	MCAL_Gpio_Init(R0_PORT, &PinConfig);

	PinConfig.pinNumber = R1_PIN;
	PinConfig.mode = GPIO_INPUT_Analog_PU;
	MCAL_Gpio_Init(R1_PORT, &PinConfig);

	PinConfig.pinNumber = R2_PIN;
	PinConfig.mode = GPIO_INPUT_Analog_PU;
	MCAL_Gpio_Init(R2_PORT, &PinConfig);

	PinConfig.pinNumber = R3_PIN;
	PinConfig.mode = GPIO_INPUT_Analog_PU;
	MCAL_Gpio_Init(R3_PORT, &PinConfig);

	// Initialize columns as output

	PinConfig.pinNumber = C0_PIN;
	PinConfig.mode = GPIO_OUTPUT_Push_Pull;
	PinConfig.output_speed = GPIO_OUTPUT_MODE_10MHz;
	MCAL_Gpio_Init(C0_PORT, &PinConfig);
	MCAL_Gpio_WritePin(C0_PORT, C0_PIN, GPIO_PIN_RESET);

	PinConfig.pinNumber = C1_PIN;
	PinConfig.mode = GPIO_OUTPUT_Push_Pull;
	PinConfig.output_speed = GPIO_OUTPUT_MODE_10MHz;
	MCAL_Gpio_Init(C1_PORT, &PinConfig);
	MCAL_Gpio_WritePin(C1_PORT, C1_PIN, GPIO_PIN_RESET);

	PinConfig.pinNumber = C2_PIN;
	PinConfig.mode = GPIO_OUTPUT_Push_Pull;
	PinConfig.output_speed = GPIO_OUTPUT_MODE_10MHz;
	MCAL_Gpio_Init(C2_PORT, &PinConfig);
	MCAL_Gpio_WritePin(C2_PORT, C2_PIN, GPIO_PIN_RESET);

	PinConfig.pinNumber = C3_PIN;
	PinConfig.mode = GPIO_OUTPUT_Push_Pull;
	PinConfig.output_speed = GPIO_OUTPUT_MODE_10MHz;
	MCAL_Gpio_Init(C3_PORT, &PinConfig);
	MCAL_Gpio_WritePin(C3_PORT, C3_PIN, GPIO_PIN_RESET);
}

char HAL_KEYPAD_GET_KEY(void) {

	for(volatile uint8_t col = 0; col < KEYPAD_COLUMS; col++)
	{
		MCAL_Gpio_WritePin(C0_PORT, C0_PIN, GPIO_PIN_SET);
		MCAL_Gpio_WritePin(C1_PORT, C1_PIN, GPIO_PIN_SET);
		MCAL_Gpio_WritePin(C2_PORT, C2_PIN, GPIO_PIN_SET);
		MCAL_Gpio_WritePin(C3_PORT, C3_PIN, GPIO_PIN_SET);

		MCAL_Gpio_WritePin(KEYPAD_COL_PORT[col], KEYPAD_COL_PIN[col], GPIO_PIN_RESET);

		for(volatile uint8_t row = 0; row < KEYPAD_ROWS; row++)
		{
			if(MCAL_Gpio_ReadPin(KEYPAD_ROW_PORT[row], KEYPAD_ROW_PIN[row]) == GPIO_PIN_RESET)
			{
				while(MCAL_Gpio_ReadPin(KEYPAD_ROW_PORT[row], KEYPAD_ROW_PIN[row]) == GPIO_PIN_RESET);
				return KEYPAD_keys[row][col];
			}
			delay_ms(25);
		}
	}
	return 0;

}
