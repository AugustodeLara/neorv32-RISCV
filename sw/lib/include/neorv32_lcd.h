/**********************************************************************//**
 * @file neorv32_lcd.h
 * @brief Liquid Crystal Display (LCD) HW driver header file.
 *
 * @note These functions should only be used if the GPIO unit was synthesized (IO_GPIO_EN = true).
 **************************************************************************/

#ifndef neorv32_lcd_h
#define neorv32_lcd_h

/**********************************************************************//**
 * @name Definitions
 **************************************************************************/
/**@{*/
/** 64 pins of output GPIOs*/
#define ALL_PINS 0x00000FFFFFFF0000
/**@{*/

/**********************************************************************//**
 * @name Prototypes
 **************************************************************************/
/**@{*/
void neorv32_lcd_clear_display(void);
void neorv32_lcd_return_to_origin(void);
void neorv32_lcd_display_on(void);
void neorv32_lcd_move_cursor_left(int n);
void neorv32_lcd_move_cursor_right(int n);
void neorv32_lcd_write(const char *message);
/**@}*/


#endif // neorv32_lcd_h
