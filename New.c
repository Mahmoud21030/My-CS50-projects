/*
 * MCU.c
 *
 * Created: 9/27/2022 9:43:44 PM
 *  Author: Umars
 */

/************************************************************************/
/*			                  	MCU-Layer	             	 		     */
/************************************************************************/

#include "MCU.h"

void inti(uint8_t PORT, uint8_t pin, bool dirc)
{
  switch (PORT)
  {
  case PORT_A:
    if (dirc == 1)
    {
      set_bit(DDRA, pin);
    }
    else if (dirc == 0)
    {
      clear_bit(DDRA, pin);
    }
    break;

  case PORT_B:
    if (dirc == 1)
    {
      set_bit(DDRB, pin);
    }
    else if (dirc == 0)
    {
      clear_bit(DDRB, pin);
    }
    break;

  case PORT_C:
    if (dirc == 1)
    {
      set_bit(DDRC, pin);
    }
    else if (dirc == 0)
    {
      clear_bit(DDRC, pin);
    }
    break;

  case PORT_D:
    if (dirc == 1)
    {
      set_bit(DDRD, pin);
    }
    else if (dirc == 0)
    {
      clear_bit(DDRD, pin);
    }
    break;
  }
}

/**
 * It takes in a port, pin, and data, and then sets the pin to the data
 *  PORT The port you want to write to.
 *  pin The pin number you want to write to.
 *  data 1 or 0
 */
void D_write(uint8_t PORT, uint8_t pin, bool data)
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

/**
 * It reads the value of a pin on a port and stores it in a variable
 *
 * @param PORT The port you want to read from.
 * @param pin The pin you want to read from.
 * @param dest The destination variable to store the read value in.
 */
void D_read(uint8_t PORT, uint8_t pin, uint8_t *dest)
{
  switch (PORT)
  {
  case PORT_A:
    *dest = (PINA && (1 << pin)) >> pin;
    break;

  case PORT_B:
    *dest = (PINB && (1 << pin)) >> pin;
    break;

  case PORT_C:
    *dest = (PINC && (1 << pin)) >> pin;
    break;

  case PORT_D:
    *dest = (PIND && (1 << pin)) >> pin;
    break;
  }
}

// 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
