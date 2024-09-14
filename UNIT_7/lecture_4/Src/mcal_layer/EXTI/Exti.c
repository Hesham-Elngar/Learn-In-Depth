/*
 * Exti.c
 *
 *  Created on: Aug 12, 2024
 *      Author: super magic
 */

#include "mcal_layer/EXTI/Exti.h"


#define AFIO_EXTI_MAPPING(x) (\
							 (x==GPIOA)?0:\
							 (x==GPIOB)?1:\
							 (x==GPIOC)?2:\
							 (x==GPIOD)?3:-1)

void (*GP_IRQ_callBack[16])(void);

static void EXTI_NVIC_DISABLE(uint16_t x)
{
	switch (x) {
	case EXTI0:
				NVIC_EXTI0_IRQ6_DISABLE;
				break;
	case EXTI1:
				NVIC_EXTI1_IRQ7_DISABLE;
				break;
	case EXTI2:
				NVIC_EXTI2_IRQ8_DISABLE;
				break;
	case EXTI3:
				NVIC_EXTI3_IRQ9_DISABLE;
				break;
	case EXTI4:
				NVIC_EXTI4_IRQ10_DISABLE;
				break;
	case EXTI5:
	case EXTI6:
	case EXTI7:
	case EXTI8:
	case EXTI9:
				NVIC_EXTI5_9_IRQ23_DISABLE;
				break;
	case EXTI10:
	case EXTI11:
	case EXTI12:
	case EXTI13:
	case EXTI14:
	case EXTI15:
				NVIC_EXTI10_15_IRQ40_DISABLE;
				break;
		default:
			break;
	}
}

static void EXTI_NVIC_ENABLE(uint16_t x)
{
	switch (x) {
	case EXTI0:
				NVIC_EXTI0_IRQ6_ENABLE;
				break;
	case EXTI1:
				NVIC_EXTI1_IRQ7_ENABLE;
				break;
	case EXTI2:
				NVIC_EXTI2_IRQ8_ENABLE;
				break;
	case EXTI3:
				NVIC_EXTI3_IRQ9_ENABLE;
				break;
	case EXTI4:
				NVIC_EXTI4_IRQ10_ENABLE;
				break;
	case EXTI5:
	case EXTI6:
	case EXTI7:
	case EXTI8:
	case EXTI9:
				NVIC_EXTI5_9_IRQ23_ENABLE;
				break;
	case EXTI10:
	case EXTI11:
	case EXTI12:
	case EXTI13:
	case EXTI14:
	case EXTI15:
				NVIC_EXTI10_15_IRQ40_ENABLE;
				break;
		default:
			break;
	}
}

static void Update_EXTI(EXTI_Pin_Config_t* EXTI_Pin_obj) {
    Gpio_PinConfig_t pin;
    pin.pinNumber = EXTI_Pin_obj->EXTI_Pin.Gpio_Pin;
    pin.mode = GPIO_INPUT_Floating;
    MCAL_Gpio_Init(EXTI_Pin_obj->EXTI_Pin.Gpio_Port, &pin);
    uint8_t AFIO_EXTICR_index 	=   (EXTI_Pin_obj->EXTI_Pin.Exti_Input_line) / 4;
    uint8_t AFIO_EXTICR_postion =   ((EXTI_Pin_obj->EXTI_Pin.Exti_Input_line)%4) * 4;

    AFIO->EXTICR[AFIO_EXTICR_index] &= ~(0xf << AFIO_EXTICR_postion);
    AFIO->EXTICR[AFIO_EXTICR_index] |= ((AFIO_EXTI_MAPPING(EXTI_Pin_obj->EXTI_Pin.Gpio_Port)& 0xF)<<AFIO_EXTICR_postion);
	//AFIO->EXTICR[AFIO_EXTICR_index] |= ((AFIO_GPIO_EXTI_Mapping(EXTI_Config->EXTI_Pin.GPIOx) & 0xF)<<AFIO_EXTICR_position);

    EXTI->RTSR &= ~(1 << EXTI_Pin_obj->EXTI_Pin.Exti_Input_line);
    EXTI->FTSR &= ~(1 << EXTI_Pin_obj->EXTI_Pin.Exti_Input_line);

    if (EXTI_Pin_obj->trigger_case == EXTI_RISING_EDGE) {
        EXTI->RTSR |= (1 << EXTI_Pin_obj->EXTI_Pin.Exti_Input_line);
    } else if (EXTI_Pin_obj->trigger_case == EXTI_FALLING_EDGE) {
        EXTI->FTSR |= (1 << EXTI_Pin_obj->EXTI_Pin.Exti_Input_line);
    } else if(EXTI_Pin_obj->trigger_case == EXTI_RISING_FALLING_EDGE){
        EXTI->RTSR |= (1 << EXTI_Pin_obj->EXTI_Pin.Exti_Input_line);
        EXTI->FTSR |= (1 << EXTI_Pin_obj->EXTI_Pin.Exti_Input_line);
    }
    GP_IRQ_callBack[EXTI_Pin_obj->EXTI_Pin.Exti_Input_line] = EXTI_Pin_obj->P_IRQ_callBack;

    if(EXTI_Pin_obj->IRQ_EN==EXTI_IRQ_Enable){
    	EXTI->IMR |= (1<< EXTI_Pin_obj->EXTI_Pin.Exti_Input_line);
    	EXTI_NVIC_ENABLE (EXTI_Pin_obj->EXTI_Pin.Exti_Input_line);
    }
    else{
    	EXTI->IMR &= ~(1<< EXTI_Pin_obj->EXTI_Pin.Exti_Input_line);
    	EXTI_NVIC_DISABLE (EXTI_Pin_obj->EXTI_Pin.Exti_Input_line);
    }
}

void MCAL_EXTI_Gpio_DeInit()
{
	EXTI->EMR=0x00000000;
	EXTI->IMR=0x00000000;
	EXTI->FTSR=0x00000000;
	EXTI->RTSR=0x00000000;
	EXTI->SWIER=0x00000000;
	EXTI->PR=0xffffffff;

	NVIC_EXTI0_IRQ6_ENABLE;
	NVIC_EXTI1_IRQ7_ENABLE;
	NVIC_EXTI2_IRQ8_ENABLE;
	NVIC_EXTI3_IRQ9_ENABLE;
	NVIC_EXTI4_IRQ10_ENABLE;
	NVIC_EXTI5_9_IRQ23_ENABLE;
	NVIC_EXTI10_15_IRQ40_ENABLE;

	NVIC_EXTI0_IRQ6_DISABLE;
	NVIC_EXTI1_IRQ7_DISABLE;
	NVIC_EXTI2_IRQ8_DISABLE;
	NVIC_EXTI3_IRQ9_DISABLE;
	NVIC_EXTI4_IRQ10_DISABLE;
	NVIC_EXTI5_9_IRQ23_DISABLE;
	NVIC_EXTI10_15_IRQ40_DISABLE;
}


void MCAL_EXTI_Gpio_Init(EXTI_Pin_Config_t* EXTI_Pin_obj)
{
	Update_EXTI(EXTI_Pin_obj);
}

void MCAL_EXTI_Gpio_Update(EXTI_Pin_Config_t* EXTI_Pin_obj)
{
	Update_EXTI(EXTI_Pin_obj);
}


void EXTI0_IRQHandler(void)
{
	EXTI->PR |= (1<<0);
	GP_IRQ_callBack[0]();
}

void EXTI1_IRQHandler(void)
{
	EXTI->PR |= (1<<1);
	GP_IRQ_callBack[1]();
}

void EXTI2_IRQHandler(void)
{
	EXTI->PR |= (1<<2);
	GP_IRQ_callBack[2]();
}

void EXTI3_IRQHandler(void)
{
	EXTI->PR |= (1<<3);
	GP_IRQ_callBack[3]();
}

void EXTI4_IRQHandler(void)
{
	EXTI->PR |= (1<<4);
	GP_IRQ_callBack[4]();
}

void EXTI9_5_IRQHandler(void)
{
	if(EXTI->PR & (1<<5)) {EXTI->PR |= (1<<5); GP_IRQ_callBack[5]();};
	if(EXTI->PR & (1<<6)) {EXTI->PR |= (1<<6); GP_IRQ_callBack[6]();};
	if(EXTI->PR & (1<<7)) {EXTI->PR |= (1<<7); GP_IRQ_callBack[7]();};
	if(EXTI->PR & (1<<8)) {EXTI->PR |= (1<<8); GP_IRQ_callBack[8]();};
	if(EXTI->PR & (1<<9)) {EXTI->PR |= (1<<9); GP_IRQ_callBack[9]();};
}

void EXTI15_10_IRQHandler(void)
{
	if(EXTI->PR & (1<<10)) {EXTI->PR |= (1<<10); GP_IRQ_callBack[10]();};
	if(EXTI->PR & (1<<11)) {EXTI->PR |= (1<<11); GP_IRQ_callBack[11]();};
	if(EXTI->PR & (1<<12)) {EXTI->PR |= (1<<12); GP_IRQ_callBack[12]();};
	if(EXTI->PR & (1<<13)) {EXTI->PR |= (1<<13); GP_IRQ_callBack[13]();};
	if(EXTI->PR & (1<<14)) {EXTI->PR |= (1<<14); GP_IRQ_callBack[14]();};
	if(EXTI->PR & (1<<15)) {EXTI->PR |= (1<<15); GP_IRQ_callBack[15]();};
}


