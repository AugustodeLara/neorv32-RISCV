/************************************************************//**
 * @file demo_lcd/main.c
 * @author J.C.E. Barcellos
 * @author Y.A. Guevara
 * @brief A simple LCD application.
 ***************************************************************/
#include <neorv32.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
/************************************************************//**
 * @brief Prints a series of sentences into the LCD.
 *
 * @note This program requires the GPIO controller to be synthesized.
 *
 * @return Will never return.
 ***************************************************************/
int main() {

	// turn on the LCD with a blinking cursor
	neorv32_lcd_display_on(); 

	// writes the first sentence to the LCD
	neorv32_lcd_write("Hello, guys!"); 
	neorv32_cpu_delay_ms(500);

	// clear the LCD and return the cursor to its origin
	neorv32_lcd_clear_display(); 
	neorv32_lcd_return_to_origin(); 
	neorv32_cpu_delay_ms(500);

	// writes the second and last sentence to the LCD
	neorv32_lcd_write("How are you?? ;)"); 

	// go to sleep mode
    while(1) {
        neorv32_cpu_sleep();
    }
	
	return 0; // this should never be reached
}