/************************************************************//**
 * @file demo_uart/main.c
 * @author J.C.E. Barcellos
 * @brief A simple UART application.
 ***************************************************************/
#include <neorv32.h>
#include <stdio.h>
#include <string.h>

// defines
#define BAUD_RATE 19200

// prototypes
void uart_irq_handler(void);

/************************************************************//**
 * @brief Every time it receives the question "Are you alright?" it will respond with "I'm alive".
 *
 * @note This program requires the UART and the GPIO controller to be synthesized.
 *
 * @return Will never return.
 ***************************************************************/
int main() {

    neorv32_gpio_port_set(0x00000FFFFFFF0000); // clear all GPIOs pins

    // initialize the UART with default baud rate
    neorv32_uart0_setup(BAUD_RATE, 0);

    // initialize the runtime environment, to handling all CPU's traps
    neorv32_rte_setup();

    // check if UART controller was synthesized.
    if (neorv32_uart0_available() == 0) {
        neorv32_gpio_pin_set(0x01);
    }

    // install handler functions for UART
    if (neorv32_rte_handler_install(RTE_TRAP_FIRQ_3, uart_irq_handler) != 0) {
        neorv32_gpio_port_set(0x02);
    }

    // go to sleep mode
    while(1) {
        neorv32_cpu_sleep();
    }

    return 0; // this should never be reached
}


/************************************************************//**
 * @brief UART IRQ handler.
 ***************************************************************/
void uart_irq_handler(void) {
    char tmp;

    // Check if the received character matches the interrupt character
    if (neorv32_uart0_char_received()) {
        tmp = neorv32_uart0_char_received_get();
        if (strcmp(&tmp, "Are you alright?")){
            // Print a message when the interrupt character is received
            neorv32_uart0_printf("I'm alive!");    
        }
    }        
}
