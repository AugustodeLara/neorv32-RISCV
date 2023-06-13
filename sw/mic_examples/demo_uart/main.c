/**//
 
@file demo_uart/main.c
@author J.C.E. Barcellos
@brief A simple UART application.
*
/
#include <neorv32.h>
#include <stdio.h>
#include <string.h>

// defines
#define BAUD_RATE 19200

// prototypes
void uart_irq_handler(void);

/**//
 
@brief Every time it receives the question "Are you alright?" it will respond with "I'm alive".*
@note This program requires the UART and the GPIO controller to be synthesized.
*
@return Will never return.
*
/
int main() {

    char buffer[50]; // buffer for the received message

    // initialize the UART with default baud rate
    neorv32_uart0_setup(BAUD_RATE, 0);

    // initialize the runtime environment, to handling all CPU's traps
    neorv32_rte_setup();

    // check if UART controller was synthesized.
    // if (neorv32_uart0_available() == 0) {
    //     neorv32_gpio_pin_set(0x01);
    // }


    while(1) {
        // send a message for the user and waits for a response
        neorv32_uart0_printf("Hi! \n");
        neorv32_uart0_scan(buffer, 50, 1);
        neorv32_uart0_printf("\n");

        // compares the response with the expected one
        if (!strcmp(buffer, "Are you alright?")) {
            neorv32_uart0_printf("\n I'm alive! \n");
            neorv32_uart0_printf("=) \n");
            neorv32_uart0_printf("NEORV32 left the conversation... \n");
        }

        // go to sleep mode
        // but you could remove it, to start a new interaction
        while(1) {
            neorv32_cpu_sleep();
        }
    }

    return 0; // this should never be reached
}
