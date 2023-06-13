/************************************************************//**
 * @file demo_blink_led/main.c
 * @author J.C.E. Barcellos
 * @brief A simple GPIO application.
 ***************************************************************/
#include <neorv32.h>
/************************************************************//**
 * @brief Shows an incrementing 8-bit counter on LEDR[7..0].
 *
 * @note This program requires the GPIO controller to be synthesized.
 *
 * @return Will never return.
 ***************************************************************/
int main() {

	int cnt = 0; // counter
	
	while (1) {
		neorv32_gpio_port_set((cnt++ & 0xFF) << 9); // increment counter and mask for lowest 8 bits
		neorv32_cpu_delay_ms(500); // wait 500ms
	}
	
	return 0; // this should never be reached
}