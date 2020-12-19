
#include "LED2.h"

void LED2_Init()
{
	DIO_setPinDirection(LED2_PORT, LED2_PIN, DIO_PIN_OUTPUT);
}

void LED2_ON()
{
	DIO_setPinValue(LED2_PORT, LED2_PIN, DIO_PIN_HIGH);
}

void LED2_OFF()
{
	DIO_setPinValue(LED2_PORT, LED2_PIN, DIO_PIN_LOW);
}

void LED2_TOGGLE()
{
	DIO_togglePin(LED2_PORT, LED2_PIN);
}
