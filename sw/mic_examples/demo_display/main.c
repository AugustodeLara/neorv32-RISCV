/************************************************************//**
 * @file demo_lcd/main.c
 * @author J.C.E. Barcellos
 * @brief A simple 7-segment display application.
 ***************************************************************/
#include <neorv32.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
/************************************************************//**
 * @brief Prints 0 to 15 in hex format into the 7-segment display.
 *
 * @note This program requires the GPIO controller to be synthesized.
 *
 * @return Will never return.
 ***************************************************************/
int main() {

	char display_chars[] = "0123456789ABCDEF"; // characters to be displayed in sequence
	int num_chars = sizeof(display_chars) - 1; // -1 to exclude the null terminator

	while (1) {
		for (int i = 0; i < num_chars; i++) {
			neorv32_display_write(CHANNEL_2, &display_chars[i]); // display each charater to the 7-segment display
			neorv32_cpu_delay_ms(500); // wait 1s
		}
		neorv32_display_clear(CHANNEL_2); // clears the 7-segment display
		neorv32_cpu_delay_ms(2000); // wait 2s
	}

	return 0; // this should never be reached
}