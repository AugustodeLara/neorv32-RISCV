/************************************************************//**
 * @file demo_xirq/main.c
 * @author J.C.E. Barcellos
 * @brief A simple external interruption application.
 ***************************************************************/
#include <neorv32.h>
#include <string.h>

// prototypes
void button_xirq_handler(void);

/************************************************************//**
 * @brief Toggles a LED every every time a button is pressed.
 *
 * @note This program requires the XIRQ and the GPIO controller to be synthesized.
 *
 * @return Will never return.
 ***************************************************************/
int main() {

    neorv32_gpio_port_set(0x00000FFFFFFF0000); // clear all GPIOs pins

    // initialize the runtime environment, to handling all CPU's traps
    neorv32_rte_setup();

    // check if XIRQ controller was synthesized.
    if (neorv32_xirq_available() == 0) {
        neorv32_gpio_port_set(0x01);
    }

    // initialize the XIRQ controller
    if (neorv32_xirq_setup() != 0) {
        neorv32_gpio_port_set(0x02);
    }

    // install handler functions for XIRQ 
    if (neorv32_xirq_install(0, button_xirq_handler) != 0) {
        neorv32_gpio_port_set(0x03);
    }

    // enable XIRQ interrupts
    neorv32_xirq_global_enable();

    // enable machine-mode interrupts
    neorv32_cpu_csr_set(CSR_MSTATUS, 1 << CSR_MSTATUS_MIE);

    while(1){
        neorv32_cpu_sleep();
    }

    return 0;
}

/**********************************************************************//**
 * @brief XIRQ handler.
 **************************************************************************/
void button_button_xirq_handler(void) {
    neorv32_gpio_pin_toggle(0<<8); // toggle the LEDR[0]
}