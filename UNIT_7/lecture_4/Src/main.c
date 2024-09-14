#include "HAL_layer/LCD/lcd.h"
#include "HAL_layer/Keypad/Keypad.h"
#include "mcal_layer/EXTI/Exti.h"
volatile char value = 0;
volatile uint8_t irq_flag = 0;

void isr() {
    value++;
    irq_flag = 1;  // Set a flag to indicate the interrupt occurred
    EXTI->PR |= (1 << 9);  // Clear the interrupt flag in the EXTI PR register
}

EXTI_Pin_Config_t EXTI_Pin_obj={
		.IRQ_EN=EXTI_IRQ_Enable,.P_IRQ_callBack=isr,.trigger_case=EXTI_RISING_EDGE,.EXTI_Pin=EXTI9PB9
};

int main(void)
{
	RCC_GPIOA_EN_CLK();
	RCC_GPIOB_EN_CLK();
	RCC_AFIO_EN_CLK();
	HAL_LCD_INIT();
	MCAL_EXTI_Gpio_Init(&EXTI_Pin_obj);
	/* Loop forever */
	while (1)
	{
		 if (irq_flag) {
		            irq_flag = 0;  // Reset the flag
		            HAL_LCD_WRITE_STRING("IRQ 9 OCCURRED");
		            HAL_LCD_WRITE_CHAR(value);
		            delay_ms(1000);  // This delay can now be safely used
		        }
	}
}
