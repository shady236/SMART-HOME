
#ifndef DIO_H_
#define DIO_H_

#include "ATmega32_Registers.h"
#include "BIT_Math.h"
#include "STD.h"

#define DIO_PORT_INPUT  0x00
#define DIO_PORT_OUTPUT 0xFF

#define DIO_PORT_HIGH  0xFF
#define DIO_PORT_LOW   0x00

#define DIO_PIN_INPUT  0
#define DIO_PIN_OUTPUT 1

#define DIO_PIN_HIGH  1
#define DIO_PIN_LOW   0


#define DIO_PORTA 0
#define DIO_PORTB 1
#define DIO_PORTC 2
#define DIO_PORTD 3

#define DIO_PIN0 0
#define DIO_PIN1 1
#define DIO_PIN2 2
#define DIO_PIN3 3
#define DIO_PIN4 4
#define DIO_PIN5 5
#define DIO_PIN6 6
#define DIO_PIN7 7

void DIO_setPortDirection(uint8 port, uint8 direction);
void DIO_setPortValue(uint8 port, uint8 value);
void DIO_readPortValue(uint8 port, uint8* value);
void DIO_togglePort(uint8 port);

void DIO_setPinDirection(uint8 port, uint8 pin, uint8 direction);
void DIO_setPinValue(uint8 port, uint8 pin, uint8 value);
void DIO_readPinValue(uint8 port, uint8 pin, uint8* value);
void DIO_togglePin(uint8 port, uint8 pin);

#endif /* DIO_H_ */