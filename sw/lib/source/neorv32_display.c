/**********************************************************************//**
 * @file neorv32_display.c
 * @brief 7-Segment Display HW driver source file.
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
 * @brief Converting the character to a binary value, to display into the 7-segment display
 *
 * @param[in] value is the character to be written to the display.
 **************************************************************************/
uint8_t neorv32_display_convert(char *value){

    uint8_t p = 0;

    switch(*value){
        case '0':
            p = 0b0111111; // "0"          
            break;
        case '1':
            p = 0b0000110; // "1"
            break;         
        case '2':
            p = 0b1011011; // "2"
            break;         
        case '3':
            p = 0b1001111; // "3"         
            break;
        case '4':
            p = 0b1100110; // "4"         
            break;
        case '5':
            p = 0b1101101; // "5"         
            break;
        case '6':
            p = 0b1111101; // "6"        
            break;
        case '7':
            p = 0b0000111; // "7"
            break;
        case '8':
            p = 0b1111111; // "8"
            break;
        case '9':
            p = 0b1101111; // "9"
            break;
        case 'A':
            p = 0b1110111; // 'A'
            break;
        case 'B':
            p = 0b1111100; // 'b'
            break;
        case 'C':
            p = 0b0111001; // 'C'
            break;
        case 'D':
            p = 0b1011110; // 'd'
            break;
        case 'E':
            p = 0b1111001; // 'E'
            break;
        case 'F':
            p = 0b1110001; // 'F'
            break;
        case 'G':
            p = 0b0111101; // 'G'
            break;
        case 'H':
            p = 0b1110110; // 'H'
            break;
        case 'I':
            p = 0b0000110; // 'I'
            break;
        case 'J':
            p = 0b0001110; // 'J'
            break;
        case 'K':
            p = 0b1110110; // 'K'  (same as 'H')
            break;
        case 'L':
            p = 0b0111000; // 'L'
            break;
        case 'M':
            p = 0b0000000; // 'M'  (no display)
            break;
        case 'N':
            p = 0b1010100; // 'n'
            break;
        case 'O':
            p = 0b0111111; // 'O'
            break;
        case 'P':
            p = 0b1110011; // 'P'
            break;
        case 'Q':
            p = 0b1100111; // 'q'
            break;
        case 'R':
            p = 0b1010000; // 'r'
            break;
        case 'S':
            p = 0b1101101; // 'S'
            break;
        case 'T':
            p = 0b1111000; // 't'
            break;
        case 'U':
            p = 0b0111110; // 'U'
            break;
        case 'V':
            p = 0b0111110; // 'V'  (same as 'U')
            break;
        case 'W':
            p = 0b0000000; // 'W'  (no display)
            break;
        case 'X':
            p = 0b1110110; // 'X'  (same as 'H')
            break;
        case 'Y':
            p = 0b1101110; // 'y'
            break;
        case 'Z':
            p = 0b1011011; // 'Z'  (same as '2')
            break;
        case ' ':
            p = 0b0000000; // ' '  (blank)
            break;
        case '-':
            p = 0b1000000; // 37  '-'  
            break;
    };

    return ~p;
}


/**********************************************************************//**
 * @brief Write a character in the display.
 *
 * @param[in] value is the character to be written to the display.
 **************************************************************************/
void neorv32_display_write(int channel, char *value){
    
    neorv32_gpio_port_set((uint64_t)neorv32_display_convert(value) <<  channel);
}
