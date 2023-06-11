/**********************************************************************//**
 * @file neorv32_lcd.c
 * @brief Liquid Crystal Display (LCD) HW driver source file.
 *
 * @note These functions should only be used if the GPIO unit was synthesized (IO_GPIO_EN = true).
 **************************************************************************/
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#include "neorv32.h"
#include "neorv32_gpio.h"
#include "neorv32_lcd.h"


/**********************************************************************//**
 * @brief Turn on the display, with a blinking cursor.
 **************************************************************************/
void neorv32_lcd_display_on(void){
    
    neorv32_gpio_port_set(0);

    neorv32_gpio_port_set((uint64_t)0x08 << 60 | (uint64_t)0x00 << 56 | (uint64_t)0x00 << 52);
    neorv32_cpu_delay_ms(10);
    neorv32_gpio_port_set((uint64_t)0x08 << 60 | (uint64_t)0x03 << 56 | (uint64_t)0x08 << 52);
    neorv32_cpu_delay_ms(10);
    neorv32_gpio_port_set((uint64_t)0x09 << 60 | (uint64_t)0x03 << 56 | (uint64_t)0x08 << 52);
    neorv32_cpu_delay_ms(10);
    neorv32_gpio_port_set((uint64_t)0x08 << 60 | (uint64_t)0x03 << 56 | (uint64_t)0x08 << 52);
    neorv32_cpu_delay_ms(10);
    neorv32_gpio_port_set((uint64_t)0x08 << 60 | (uint64_t)0x00 << 56 | (uint64_t)0x0F << 52);
    neorv32_cpu_delay_ms(10);
    neorv32_gpio_port_set((uint64_t)0x09 << 60 | (uint64_t)0x00 << 56 | (uint64_t)0x0F << 52);
    neorv32_cpu_delay_ms(10);
    neorv32_gpio_port_set((uint64_t)0x08 << 60 | (uint64_t)0x00 << 56 | (uint64_t)0x0F << 52);
    neorv32_cpu_delay_ms(10);
}

/**********************************************************************//**
 * @brief Clear the display
 **************************************************************************/
void neorv32_lcd_clear_display(void){

    neorv32_gpio_port_set((uint64_t)0x08 << 60 | (uint64_t)0x00 << 56 | (uint64_t)0x01 << 52);
    neorv32_cpu_delay_ms(10);
    neorv32_gpio_port_set((uint64_t)0x09 << 60 | (uint64_t)0x00 << 56 | (uint64_t)0x01 << 52);
    neorv32_cpu_delay_ms(10);
}

/**********************************************************************//**
 * @brief Return the display's cursor to the origin.
 **************************************************************************/
void neorv32_lcd_return_to_origin(void){

    neorv32_gpio_port_set((uint64_t)0x08 << 60 | (uint64_t)0x00 << 56 | (uint64_t)0x02 << 52);
    neorv32_cpu_delay_ms(10);
    neorv32_gpio_port_set((uint64_t)0x09 << 60 | (uint64_t)0x00 << 56 | (uint64_t)0x02 << 52);
    neorv32_cpu_delay_ms(10);
}

/**********************************************************************//**
 * @brief Move cursor to the left.
 *
 * @param[in] n is the number of times the cursor is going to the left.
 **************************************************************************/
void neorv32_lcd_move_cursor_left(int n){

    int i = 0; 

    for(i = 0; i<=n; i++){
        neorv32_gpio_port_set((uint64_t)0x08 << 60 | (uint64_t)0x01 << 56 | (uint64_t)0x00 << 52);
        neorv32_cpu_delay_ms(10);
        neorv32_gpio_port_set((uint64_t)0x09 << 60 | (uint64_t)0x01 << 56 | (uint64_t)0x00 << 52);
        neorv32_cpu_delay_ms(10);
    }
}

/**********************************************************************//**
 * @brief Move cursor to the right.
 *
 * @param[in] n is the number of times the cursor is going to the right.
 **************************************************************************/
void neorv32_lcd_move_cursor_right(int n){

    int i = 0; 

    for(i = 0; i<=n; i++){
        neorv32_gpio_port_set((uint64_t)0x08 << 60 | (uint64_t)0x01 << 56 | (uint64_t)0x04 << 52);
        neorv32_cpu_delay_ms(10);
        neorv32_gpio_port_set((uint64_t)0x09 << 60 | (uint64_t)0x01 << 56 | (uint64_t)0x04 << 52);
        neorv32_cpu_delay_ms(10);
    }
}

/**********************************************************************//**
 * @brief Write a sentence in the display.
 *
 * @param[in] message is the sentence to be written to the display.
 **************************************************************************/
void neorv32_lcd_write(const char *message){

    size_t word_len = strlen(message);
    uint64_t h = 0;
    uint64_t l = 0;

    for (size_t i = 0; i <= word_len; i++) {
        h = (message[i] & 0xF0) >> 4;
        l = (message[i] & 0x0F);

        neorv32_gpio_port_set((uint64_t)0x06  <<  60 | h  <<  56 | l  <<  52);
        neorv32_cpu_delay_ms(10);
        neorv32_gpio_port_set((uint64_t)0x0D  <<  60 | h  <<  56 | l  <<  52);
        neorv32_cpu_delay_ms(10);
    }

}
