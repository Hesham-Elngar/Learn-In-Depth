/*
 * lcd.c
 *
 *  Created on: Aug 5, 2024
 *      Author: super magic
 */

#include "HAL_layer/LCD/lcd.h"
#include "HAL_layer/LCD/lcd_config.h"

#if LCD_MODE == LCD_8_BIT_MODE
static void LCD_8BIT_INIT(void)
{
    Gpio_PinConfig_t PinConfig;

    // Initialize control pins
    PinConfig.pinNumber = LCD_RS_PIN;
    PinConfig.mode = GPIO_OUTPUT_Push_Pull;
    PinConfig.output_speed = GPIO_OUTPUT_MODE_10MHz;
    MCAL_Gpio_Init(LCD_RS_PORT, &PinConfig);

    PinConfig.pinNumber = LCD_RW_PIN;
    MCAL_Gpio_Init(LCD_RW_PORT, &PinConfig);

    PinConfig.pinNumber = LCD_EN_PIN;
    MCAL_Gpio_Init(LCD_EN_PORT, &PinConfig);

    // Initialize data pins
    for (int pin = LCD_D0_PIN; pin <= LCD_D7_PIN; pin++)
    {
        PinConfig.pinNumber = pin;
        MCAL_Gpio_Init(LCD_D0_PORT, &PinConfig); // Assuming all data pins are on the same port
    }

    // Reset control pins
    MCAL_Gpio_WritePin(LCD_EN_PORT, LCD_EN_PIN, GPIO_PIN_RESET);
    MCAL_Gpio_WritePin(LCD_RS_PORT, LCD_RS_PIN, GPIO_PIN_RESET);
    MCAL_Gpio_WritePin(LCD_RW_PORT, LCD_RW_PIN, GPIO_PIN_RESET);
}

static void HAL_8BIT_LCD_KICK(void)
{
    MCAL_Gpio_WritePin(LCD_EN_PORT, LCD_EN_PIN, GPIO_PIN_SET);
    delay_ms(50);
    MCAL_Gpio_WritePin(LCD_EN_PORT, LCD_EN_PIN, GPIO_PIN_RESET);
}

#elif LCD_MODE == LCD_4_BIT_MODE

static void LCD_4BIT_INIT(void)
{
    Gpio_PinConfig_t PinConfig;

    // Initialize control pins
    PinConfig.pinNumber = LCD_RS_PIN;
    PinConfig.mode = GPIO_OUTPUT_Push_Pull;
    PinConfig.output_speed = GPIO_OUTPUT_MODE_10MHz;
    MCAL_Gpio_Init(LCD_RS_PORT, &PinConfig);

    PinConfig.pinNumber = LCD_RW_PIN;
    MCAL_Gpio_Init(LCD_RW_PORT, &PinConfig);

    PinConfig.pinNumber = LCD_EN_PIN;
    MCAL_Gpio_Init(LCD_EN_PORT, &PinConfig);

    // Initialize data pins
    for (int pin = LCD_D4_PIN; pin <= LCD_D7_PIN; pin++)
    {
        PinConfig.pinNumber = pin;
        MCAL_Gpio_Init(LCD_D4_PORT, &PinConfig); // Assuming all data pins are on the same port
    }

    // Reset control pins
    MCAL_Gpio_WritePin(LCD_EN_PORT, LCD_EN_PIN, GPIO_PIN_RESET);
    MCAL_Gpio_WritePin(LCD_RS_PORT, LCD_RS_PIN, GPIO_PIN_RESET);
    MCAL_Gpio_WritePin(LCD_RW_PORT, LCD_RW_PIN, GPIO_PIN_RESET);
}

static void HAL_4BIT_LCD_KICK(void)
{
    MCAL_Gpio_WritePin(LCD_EN_PORT, LCD_EN_PIN, GPIO_PIN_SET);
    delay_ms(5);
    MCAL_Gpio_WritePin(LCD_EN_PORT, LCD_EN_PIN, GPIO_PIN_RESET);
}
#endif

void HAL_LCD_CLEAR_SCREEN(void)
{
    HAL_LCD_WRITE_COMMAND(LCD_CMD_CLEAR_SCREEN);
}

void HAL_LCD_GOTO_XY(uint8_t line, uint8_t position)
{
	position--;
    if (line == 1 && position < 16)
    {
        HAL_LCD_WRITE_COMMAND(LCD_CMD_BEGIN_AT_FIRST_ROW + position);
    }
    else if (line == 2 && position < 16)
    {
        HAL_LCD_WRITE_COMMAND(LCD_CMD_BEGIN_AT_SECOND_ROW + position);
    }
}

void HAL_LCD_INIT(void)
{
    delay_ms(20);

#if LCD_MODE == LCD_8_BIT_MODE
    LCD_8BIT_INIT();
    delay_ms(15);
    HAL_LCD_CLEAR_SCREEN();
    HAL_LCD_WRITE_COMMAND(LCD_CMD_FUNCTION_8BIT_2LINES);
    HAL_LCD_WRITE_COMMAND(LCD_CMD_ENTRY_MODE);
    HAL_LCD_WRITE_COMMAND(LCD_CMD_BEGIN_AT_FIRST_ROW);
    HAL_LCD_WRITE_COMMAND(LCD_CMD_DISP_ON_CURSOR_BLINK);
#elif LCD_MODE == LCD_4_BIT_MODE
    LCD_4BIT_INIT();
    delay_ms(15);
    HAL_LCD_WRITE_COMMAND(0x02); // As per datasheet
    HAL_LCD_WRITE_COMMAND(LCD_CMD_FUNCTION_4BIT_2LINES);
    HAL_LCD_WRITE_COMMAND(LCD_CMD_ENTRY_MODE);
    HAL_LCD_WRITE_COMMAND(LCD_CMD_BEGIN_AT_FIRST_ROW);
    HAL_LCD_WRITE_COMMAND(LCD_CMD_DISP_ON_CURSOR_BLINK);
#endif
}

void HAL_LCD_ISBUSY(void)
{
    Gpio_PinConfig_t PinConfig;
    PinConfig.mode = GPIO_INPUT_Floating;
#if LCD_MODE == LCD_8_BIT_MODE
    for (int pin = LCD_D0_PIN; pin <= LCD_D7_PIN; pin++)
    {
        PinConfig.pinNumber = pin;
        MCAL_Gpio_Init(LCD_D0_PORT, &PinConfig); // Assuming all data pins are on the same port
    }
    MCAL_Gpio_WritePin(LCD_RW_PORT, LCD_RW_PIN, GPIO_PIN_SET);
    MCAL_Gpio_WritePin(LCD_RS_PORT, LCD_RS_PIN, GPIO_PIN_RESET);
    HAL_8BIT_LCD_KICK();
#elif LCD_MODE == LCD_4_BIT_MODE
    for (int pin = LCD_D4_PIN; pin <= LCD_D7_PIN; pin++)
    {
        PinConfig.pinNumber = pin;
        MCAL_Gpio_Init(LCD_D4_PORT, &PinConfig); // Assuming all data pins are on the same port
    }
    MCAL_Gpio_WritePin(LCD_RW_PORT, LCD_RW_PIN, GPIO_PIN_SET);
    MCAL_Gpio_WritePin(LCD_RS_PORT, LCD_RS_PIN, GPIO_PIN_RESET);
    HAL_4BIT_LCD_KICK();
#endif
    MCAL_Gpio_WritePin(LCD_RW_PORT, LCD_RW_PIN, GPIO_PIN_RESET);
}

void HAL_LCD_WRITE_COMMAND(uint8_t command)
{
#if LCD_MODE == LCD_8_BIT_MODE
    MCAL_Gpio_WritePort(LCD_D0_PORT, command);
    MCAL_Gpio_WritePin(LCD_RS_PORT, LCD_RS_PIN, GPIO_PIN_RESET);
    MCAL_Gpio_WritePin(LCD_RW_PORT, LCD_RW_PIN, GPIO_PIN_RESET);
    HAL_8BIT_LCD_KICK();
#elif LCD_MODE == LCD_4_BIT_MODE
    MCAL_Gpio_WritePort(LCD_D4_PORT, (command & 0xF0) >> 4);
    MCAL_Gpio_WritePin(LCD_RS_PORT, LCD_RS_PIN, GPIO_PIN_RESET);
    MCAL_Gpio_WritePin(LCD_RW_PORT, LCD_RW_PIN, GPIO_PIN_RESET);
    HAL_4BIT_LCD_KICK();

    MCAL_Gpio_WritePort(LCD_D4_PORT, command & 0x0F);
    HAL_4BIT_LCD_KICK();
#endif
}

void HAL_LCD_WRITE_CHAR(uint8_t character)
{
#if LCD_MODE == LCD_8_BIT_MODE
    MCAL_Gpio_WritePort(LCD_D0_PORT, character);
    MCAL_Gpio_WritePin(LCD_RS_PORT, LCD_RS_PIN, GPIO_PIN_SET);
    MCAL_Gpio_WritePin(LCD_RW_PORT, LCD_RW_PIN, GPIO_PIN_RESET);
    HAL_8BIT_LCD_KICK();
#elif LCD_MODE == LCD_4_BIT_MODE
    MCAL_Gpio_WritePort(LCD_D4_PORT, (character & 0xF0) >> 4);
    MCAL_Gpio_WritePin(LCD_RS_PORT, LCD_RS_PIN, GPIO_PIN_SET);
    MCAL_Gpio_WritePin(LCD_RW_PORT, LCD_RW_PIN, GPIO_PIN_RESET);
    HAL_4BIT_LCD_KICK();

    MCAL_Gpio_WritePort(LCD_D4_PORT, character & 0x0F);
    HAL_4BIT_LCD_KICK();
#endif
}

void HAL_LCD_WRITE_STRING(char* string)
{
    for (int i = 0; string[i] != '\0'; i++)
    {
        HAL_LCD_WRITE_CHAR(string[i]);
    }
}

