/**********************************************************************//**
 * @file neorv32_display.h
 * @brief 7-Segment Display HW driver header file.
 *
 * @note These functions should only be used if the GPIO unit was synthesized (IO_GPIO_EN = true).
 **************************************************************************/
 
#define CHANNEL_0 16
#define CHANNEL_1 23
#define CHANNEL_2 30
#define CHANNEL_3 37

#ifndef neorv32_display_h
#define neorv32_display_h

/**********************************************************************//**
 * @name Prototypes
 **************************************************************************/
/**@{*/
void neorv32_display_clear(int channel);
void neorv32_display_write(int channel, char *value);
uint8_t neorv32_display_convert(char *value);
/**@}*/


#endif // neorv32_display_h
