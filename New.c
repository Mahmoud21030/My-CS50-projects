/*
 * MCU.c
 *
 * Created: 9/27/2022 9:43:44 PM
 *  Author: Umars
 */

/************************************************************************/
/*			                  	MCU-Layer	             	 		     */
/************************************************************************/

/**
 * It takes in a port, pin, and data, and then sets the pin to the data
 *
 * @param PORT The port you want to write to.
 * @param pin The pin number you want to write to.
 * @param data 1 or 0
 */
#include "MCU.h"

void D_write(uint8_t PORT, uint8_t pin, uint8_t data)
{
  switch (PORT)
  {
  case PORT_A:
    if (data == 1)
    {
      set_bit(PORTA, pin);
    }
    else if (data == 0)
    {
      clear_bit(PORTA, pin);
    }
    break;

  case PORT_B:
    if (data == 1)
    {
      set_bit(PORTB, pin);
    }
    else if (data == 0)
    {
      clear_bit(PORTB, pin);
    }
    break;

  case PORT_C:
    if (data == 1)
    {
      set_bit(PORTC, pin);
    }
    else if (data == 0)
    {
      clear_bit(PORTC, pin);
    }
    break;

  case PORT_D:
    if (data == 1)
    {
      set_bit(PORTD, pin);
    }
    else if (data == 0)
    {
      clear_bit(PORTD, pin);
    }
    break;
  }
}

// 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
