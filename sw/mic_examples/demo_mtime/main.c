/************************************************************//**
 * @file demo_mtime/main.c
 * @author J.C.E. Barcellos
 * @brief A simple timer application.
 ***************************************************************/
#include <neorv32.h>

// defines
#define DELAY_S 1

/************************************************************//**
 * @brief MTIME IRQ handler.
 ***************************************************************/
void mtime_irq_handler(void) {
    static int cnt = 0; // counter

    // update the time for the next interrupt
    neorv32_mtime_set_timecmp(neorv32_mtime_get_timecmp() + DELAY_S*(NEORV32_SYSINFO->CLK / 2));

    // increment counter and mask for lowest 8 bits
	neorv32_gpio_port_set((cnt++ & 0xFF)<<9); 
}

/************************************************************//**
 * @brief increments a 8-bit counter on LEDR[7..0] using the machine timer interrupt.
 *
 * @note This program requires the MTIME and the GPIO controller to be synthesized.
 *
 * @return Will never return.
 ***************************************************************/
int main() {

    // initialize the runtime environment, to handling all CPU's traps
    neorv32_rte_setup();

    // check if MTIME controller was synthesized.
    if (neorv32_mtime_available() == 0) {
        neorv32_gpio_pin_set(0x01);
    }

    // install handler functions for MTIME 
    if (neorv32_rte_handler_install(RTE_TRAP_MTI, mtime_irq_handler) != 0) {
        neorv32_gpio_pin_set(0x02);
    }

    // configure the time for the first interrupt
    neorv32_mtime_set_timecmp(neorv32_mtime_get_time() + DELAY_S*(NEORV32_SYSINFO->CLK / 2));

    // enable interrupt
    neorv32_cpu_csr_set(CSR_MIE, 1 << CSR_MIE_MTIE); // enable MTIME interrupt
    neorv32_cpu_csr_set(CSR_MSTATUS, 1 << CSR_MSTATUS_MIE); // enable machine-mode interrupts

    // go to sleep mode
    while(1) {
        neorv32_cpu_sleep();
    }

    return 0; // this should never be reached
}
