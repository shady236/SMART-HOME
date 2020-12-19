#include "DIO.h"

void DIO_setPortDirection(uint8 port, uint8 direction)
{
	switch(port)
	{
		case DIO_PORTA:
		DDRA = direction;
		break;
		
		case DIO_PORTB:
		DDRB = direction;
		break;
		
		case DIO_PORTC:
		DDRC = direction;
		break;
		
		case DIO_PORTD:
		DDRD = direction;
		break;
	}
}

void DIO_setPortValue(uint8 port, uint8 value)
{
	switch(port)
	{
		case DIO_PORTA:
		PORTA = value;
		break;
		
		case DIO_PORTB:
		PORTB = value;
		break;
		
		case DIO_PORTC:
		PORTC = value;
		break;
		
		case DIO_PORTD:
		PORTD = value;
		break;
	}
}

void DIO_readPortValue(uint8 port, uint8* value)
{
	switch(port)
	{
		case DIO_PORTA:
		*value = PINA;
		break;
		
		case DIO_PORTB:
		*value = PINB;
		break;
		
		case DIO_PORTC:
		*value = PINC;
		break;
		
		case DIO_PORTD:
		*value = PIND;
		break;
	}
}

void DIO_togglePort(uint8 port)
{
	switch(port)
	{
		case DIO_PORTA:
		PORTA = ~PORTA;
		break;
		
		case DIO_PORTB:
		PORTB = ~PORTB;
		break;
		
		case DIO_PORTC:
		PORTC = ~PORTC;
		break;
		
		case DIO_PORTD:
		PORTD = ~PORTD;
		break;
	}
}

void DIO_setPinDirection(uint8 port, uint8 pin, uint8 direction)
{
	switch(port)
	{
		case DIO_PORTA:
		if(direction==DIO_PIN_OUTPUT)
		{
			SET_BIT(DDRA, pin);
		}
		else if(direction==DIO_PIN_INPUT)
		{
			CLR_BIT(DDRA, pin);
		}
		break;
		
		case DIO_PORTB:
		if(direction==DIO_PIN_OUTPUT)
		{
			SET_BIT(DDRB, pin);
		}
		else if(direction==DIO_PIN_INPUT)
		{
			CLR_BIT(DDRB, pin);
		}
		break;
		
		case DIO_PORTC:
		if(direction==DIO_PIN_OUTPUT)
		{
			SET_BIT(DDRC, pin);
		}
		else if(direction==DIO_PIN_INPUT)
		{
			CLR_BIT(DDRC, pin);
		}
		break;
		
		case DIO_PORTD:
		if(direction==DIO_PIN_OUTPUT)
		{
			SET_BIT(DDRD, pin);
		}
		else if(direction==DIO_PIN_INPUT)
		{
			CLR_BIT(DDRD, pin);
		}
		break;
	}
}

void DIO_setPinValue(uint8 port, uint8 pin, uint8 value)
{
	switch(port)
	{
		case DIO_PORTA:
		if(value==DIO_PIN_HIGH)
		{
			SET_BIT(PORTA, pin);
		}
		else if(value==DIO_PIN_LOW)
		{
			CLR_BIT(PORTA, pin);
		}
		break;
		
		case DIO_PORTB:
		if(value==DIO_PIN_HIGH)
		{
			SET_BIT(PORTB, pin);
		}
		else if(value==DIO_PIN_LOW)
		{
			CLR_BIT(PORTB, pin);
		}
		break;
		
		case DIO_PORTC:
		if(value==DIO_PIN_HIGH)
		{
			SET_BIT(PORTC, pin);
		}
		else if(value==DIO_PIN_LOW)
		{
			CLR_BIT(PORTC, pin);
		}
		break;
		
		case DIO_PORTD:
		if(value==DIO_PIN_HIGH)
		{
			SET_BIT(PORTD, pin);
		}
		else if(value==DIO_PIN_LOW)
		{
			CLR_BIT(PORTD, pin);
		}
		break;
	}
}

void DIO_readPinValue(uint8 port, uint8 pin, uint8* value)
{
	switch(port)
	{
		case DIO_PORTA:
		*value = GET_BIT(PINA, pin);
		break;
		
		case DIO_PORTB:
		*value = GET_BIT(PINB, pin);
		break;
		
		case DIO_PORTC:
		*value = GET_BIT(PINC, pin);
		break;
		
		case DIO_PORTD:
		*value = GET_BIT(PIND, pin);
		break;
	}
}



void DIO_togglePin(uint8 port, uint8 pin)
{
	switch(port)
	{
		case DIO_PORTA:
		TOG_BIT(PORTA, pin);
		break;
		
		case DIO_PORTB:
		TOG_BIT(PORTB, pin);
		break;
		
		case DIO_PORTC:
		TOG_BIT(PORTC, pin);
		break;
		
		case DIO_PORTD:
		TOG_BIT(PORTD, pin);
		break;
	}
}