/*
 * Gpio.c
 *
 *  Created on: Aug 5, 2024
 *      Author: super magic
 */


#include "Gpio.h"

// Function to get the pin position (address offset)
uint8_t get_pin_position(uint8_t pin_number) {
    switch(pin_number) {
        case GPIO_PIN0: case GPIO_PIN8:  return 0;
        case GPIO_PIN1: case GPIO_PIN9:  return 4;
        case GPIO_PIN2: case GPIO_PIN10: return 8;
        case GPIO_PIN3: case GPIO_PIN11: return 12;
        case GPIO_PIN4: case GPIO_PIN12: return 16;
        case GPIO_PIN5: case GPIO_PIN13: return 20;
        case GPIO_PIN6: case GPIO_PIN14: return 24;
        case GPIO_PIN7: case GPIO_PIN15: return 28;
        default: return 0; // Return 0 or handle error if needed
    }
}

void MCAL_Gpio_Init(Gpio_typedef* Gpiox ,Gpio_PinConfig_t* pin){
    uint8_t pin_config = 0;
    volatile uint32_t* configRegister = NULL;

    // Determine the correct configuration register (CRL or CRH)
    if (pin->pinNumber < GPIO_PIN8) {
        configRegister = &Gpiox->CRL;
    } else {
        configRegister = &Gpiox->CRH;
    }

    // Clear the previous configuration for the pin
    *configRegister &= ~(0xF << get_pin_position(pin->pinNumber));

    // Configure the pin based on the mode
    if (pin->mode == GPIO_OUTPUT_Push_Pull ||
        pin->mode == GPIO_OUTPUT_Open_Drain ||
        pin->mode == GPIO_OUTPUT_Alternate_Push_Pull ||
        pin->mode == GPIO_OUTPUT_Alternate_Open_Drain) {

        pin_config = (((((pin->mode) - 4) << 2) | (pin->output_speed)) & 0x0F);
    } else if (pin->mode == GPIO_INPUT_Analog || pin->mode == GPIO_INPUT_Floating) {
        pin_config = (((pin->mode << 2) | 0x00) & 0x0F);
    } else if (pin->mode == GPIO_INPUT_Analog_PD || pin->mode == GPIO_INPUT_Analog_PU) {
        pin_config = (((GPIO_INPUT_Analog_PU << 2) | 0x00) & 0x0F);
        if (pin->mode == GPIO_INPUT_Analog_PU) {
            Gpiox->ODR |= (1 << pin->pinNumber);
        }
    } else {
        pin_config = (((GPIO_INTPUT_Alternate << 2) | 0x00) & 0x0F);
    }

    // Set the new configuration for the pin
    *configRegister |= (pin_config << get_pin_position(pin->pinNumber));
}

void MCAL_Gpio_DeInit(Gpio_typedef* Gpiox) {
    if (Gpiox == GPIOA) {
        RCC->APB2RSTR |= (1 << 2);
    } else if (Gpiox == GPIOB) {
        RCC->APB2RSTR |= (1 << 3);
    } else if (Gpiox == GPIOC) {
        RCC->APB2RSTR |= (1 << 4);
    } else if (Gpiox == GPIOD) {
        RCC->APB2RSTR |= (1 << 5);
    }
    // Add a delay here if necessary for the reset to take effect
    // Typically, a short delay or a reset of the peripheral would be done here
    // To reinitialize, you might need to clear the reset bit.
    // Example: RCC->APB2RSTR &= ~(1 << 2); // To clear reset for GPIOA
}

uint8_t MCAL_Gpio_ReadPin(Gpio_typedef* Gpiox, uint16_t pin) {
    return READ_BIT(Gpiox->IDR, pin);
}

void MCAL_Gpio_WritePin(Gpio_typedef* Gpiox, uint16_t pin, uint8_t value) {
    if (value == GPIO_PIN_SET) {
        SET_BIT(Gpiox->ODR, pin);
    } else if (value == GPIO_PIN_RESET) {
        CLR_BIT(Gpiox->ODR, pin);
    }
}

void MCAL_Gpio_TogglePin(Gpio_typedef* Gpiox, uint16_t pin) {
    TOG_BIT(Gpiox->ODR, pin);
}

void MCAL_Gpio_LockPin(Gpio_typedef* Gpiox, uint16_t pin) {
    // Locking the GPIO pin (typically involves setting the LCKR register)
    // This example assumes LCKR register is part of the GPIOx structure
    // You should consult the STM32 reference manual for the correct procedure
    Gpiox->LCKR |= (1 << pin);
    Gpiox->LCKR |= (1 << 16); // Set LCKK bit to lock
    Gpiox->LCKR &= ~(1 << pin); // Clear pin bit
    Gpiox->LCKR &= ~(1 << 16); // Clear LCKK bit
    Gpiox->LCKR |= (1 << 16); // Set LCKK bit to confirm
}

uint16_t MCAL_Gpio_ReadPort(Gpio_typedef* Gpiox) {
    return (uint16_t)(Gpiox->IDR & 0xFFFF);
}

void MCAL_Gpio_WritePort(Gpio_typedef* Gpiox, uint16_t value) {
    Gpiox->ODR = value;
}
void delay_ms(uint32_t delay)
{
	uint32_t i, j;
	for (i = 0; i < delay; i++)
	{
		for (j = 0; j < 255; j++);
	}
}


