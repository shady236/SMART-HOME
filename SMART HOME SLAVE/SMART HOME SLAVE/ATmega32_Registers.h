#ifndef ATMEGA32_REGISTERS_H_
#define ATMEGA32_REGISTERS_H_

#include "STD.h"

#define DDRA	(*(volatile uint8 *)(0x3A))
#define DDRB	(*(volatile uint8 *)(0x37))
#define DDRC	(*(volatile uint8 *)(0x34))
#define DDRD	(*(volatile uint8 *)(0x31))

#define PINA	(*(volatile uint8 *)(0x39))
#define PINB	(*(volatile uint8 *)(0x36))
#define PINC	(*(volatile uint8 *)(0x33))
#define PIND	(*(volatile uint8 *)(0x30))

#define PORTA	(*(volatile uint8 *)(0x3B))
#define PORTB	(*(volatile uint8 *)(0x38))
#define PORTC	(*(volatile uint8 *)(0x35))
#define PORTD	(*(volatile uint8 *)(0x32))





#define SREG	(*(volatile uint8 *)(0x5F))
#define GICR	(*(volatile uint8 *)(0x5B))
#define GIFR	(*(volatile uint8 *)(0x5A))
#define MCUCR	(*(volatile uint8 *)(0x55))
#define MCUCSR	(*(volatile uint8 *)(0x54))









#define ADMUX	(*(volatile uint8 *)(0x27))
#define ADCSRA	(*(volatile uint8 *)(0x26))
#define ADCH	(*(volatile uint8 *)(0x25))
#define ADCL	(*(volatile uint8 *)(0x24))
#define ADC_ALL	(*(volatile uint16 *)(0x24))
#define SFIOR	(*(volatile uint8 *)(0x50))









#define TCNT0	(*(volatile uint8 *)(0x52))
#define OCR0	(*(volatile uint8 *)(0x5C))
#define TCCR0	(*(volatile uint8 *)(0x53))
#define TIMSK	(*(volatile uint8 *)(0x59))
#define TIFR	(*(volatile uint8 *)(0x58))

#define TCNT1	(*(volatile uint16 *)(0x4C))
#define OCR1A	(*(volatile uint16 *)(0x4A))
#define OCR1B	(*(volatile uint16 *)(0x48))
#define TCCR1A	(*(volatile uint8 *)(0x4F))
#define TCCR1B	(*(volatile uint8 *)(0x4E))

#define TCNT2	(*(volatile uint8 *)(0x44))
#define OCR2	(*(volatile uint8 *)(0x43))
#define TCCR2	(*(volatile uint8 *)(0x45))





#define UDR		(*(volatile uint8 *)(0x2C))
#define UCSRA	(*(volatile uint8 *)(0x2B))
#define UCSRB	(*(volatile uint8 *)(0x2A))
#define UCSRC	(*(volatile uint8 *)(0x40))
#define UBRRL	(*(volatile uint8 *)(0x29))
#define UBRRH	(*(volatile uint8 *)(0x40))




typedef struct
{
	uint8 SPCR;
	uint8 SPSR;
	uint8 SPDR;
}SPI_reg;

#define SPI		((volatile SPI_reg *)(0x2D))




#endif /* ATMEGA32_REGISTERS_H_ */