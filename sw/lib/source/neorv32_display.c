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
#include "neorv32_display.h"

/**********************************************************************//**
 * @brief Clear the display
 **************************************************************************/
void neorv32_display_clear(int channel){

    neorv32_gpio_port_set((uint64_t)0x40 << channel);
}

/**********************************************************************//**
 * @brief Write a sentence in the display.
 *
 * @param[in] message is the sentence to be written to the display.
 **************************************************************************/
uint8_t neorv32_display_convert(const char *value){

    uint8_t p = 0;

    switch((int)value){
        case (int)'0':
            p = 0b0111111; // "0"          
            break;
        case (int)'1':
            p = 0b0000110; // "1"
            break;         
        case (int)'2':
            p = 0b1011011; // "2"
            break;         
        case (int)'3':
            p = 0b1001111; // "3"         
            break;
        case (int)'4':
            p = 0b1100110; // "4"         
            break;
        case (int)'5':
            p = 0b1101101; // "5"         
            break;
        case (int)'6':
            p = 0b1111101; // "6"        
            break;
        case (int)'7':
            p = 0b0000111; // "7"
            break;
        case (int)'8':
            p = 0b1111111; // "8"
            break;
        case (int)'9':
            p = 0b1101111; // "9"
            break;
        case (int)'A':
            p = 0b1110111; // 'A'
            break;
        case (int)'B':
            p = 0b1111100; // 'b'
            break;
        case (int)'C':
            p = 0b0111001; // 'C'
            break;
        case (int)'D':
            p = 0b1011110; // 'd'
            break;
        case (int)'E':
            p = 0b1111001; // 'E'
            break;
        case (int)'F':
            p = 0b1110001; // 'F'
            break;
        case (int)'G':
            p = 0b0111101; // 'G'
            break;
        case (int)'H':
            p = 0b1110110; // 'H'
            break;
        case (int)'I':
            p = 0b0000110; // 'I'
            break;
        case (int)'J':
            p = 0b0001110; // 'J'
            break;
        case (int)'K':
            p = 0b1110110; // 'K'  (same as 'H')
            break;
        case (int)'L':
            p = 0b0111000; // 'L'
            break;
        case (int)'M':
            p = 0b0000000; // 'M'  (no display)
            break;
        case (int)'N':
            p = 0b1010100; // 'n'
            break;
        case (int)'O':
            p = 0b0111111; // 'O'
            break;
        case (int)'P':
            p = 0b1110011; // 'P'
            break;
        case (int)'Q':
            p = 0b1100111; // 'q'
            break;
        case (int)'R':
            p = 0b1010000; // 'r'
            break;
        case (int)'S':
            p = 0b1101101; // 'S'
            break;
        case (int)'T':
            p = 0b1111000; // 't'
            break;
        case (int)'U':
            p = 0b0111110; // 'U'
            break;
        case (int)'V':
            p = 0b0111110; // 'V'  (same as 'U')
            break;
        case (int)'W':
            p = 0b0000000; // 'W'  (no display)
            break;
        case (int)'X':
            p = 0b1110110; // 'X'  (same as 'H')
            break;
        case (int)'Y':
            p = 0b1101110; // 'y'
            break;
        case (int)'Z':
            p = 0b1011011; // 'Z'  (same as '2')
            break;
        case (int)' ':
            p = 0b0000000; // ' '  (blank)
            break;
        case (int)'-':
            p = 0b1000000; // 37  '-'  
            break;
    };

    return p;
}


/**********************************************************************//**
 * @brief Write a sentence in the display.
 *
 * @param[in] message is the sentence to be written to the display.
 **************************************************************************/
void neorv32_display_write(int channel, const char *value){
    
    neorv32_gpio_port_set((uint64_t)(!neorv32_display_convert(value)) <<  channel);
}
