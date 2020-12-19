
#include "UART.h"
#include "SPI.h"
#include "LCD.h"
#define F_CPU	8000000UL
#include <util/delay.h>

int main(void)
{
	LCD_init();
	UART_init();
	SPI_init();
	SPI_masterStartTransmission();
	_delay_ms(1000);
	uint8 data;
	
    while(1)
    {
		data = UART_Rx();
		LCD_writeChar(data);
		SPI_Transiver(data);
    }
}