
#include "LED1.h"

void LED1_Init()
{
	DIO_setPinDirection(LED1_PORT, LED1_PIN, DIO_PIN_OUTPUT);
}

void LED1_ON()
{
	DIO_setPinValue(LED1_PORT, LED1_PIN, DIO_PIN_HIGH);
}

void LED1_OFF()
{
	DIO_setPinValue(LED1_PORT, LED1_PIN, DIO_PIN_LOW);
}

void LED1_TOGGLE()
{
	DIO_togglePin(LED1_PORT, LED1_PIN);
}
